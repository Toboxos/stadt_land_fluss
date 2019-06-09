#include "CLogik.h"
#include "spieler.h"
#include "antworten.h"
#include "punkte.h"
#include "hostspieleinstellungen.h"
#include "spielerwarteraum.h"
#include "kategorieeingabe.h"

CLogik::CLogik() : warteRaum(nullptr) {
    srand(time(NULL));
}

CLogik::~CLogik(){
    delete warteRaum;
    delete roundTimer;
}

void CLogik::run() {
    HostSpielEinstellungen einstellungen(nullptr, this);
    einstellungen.exec();
}

void CLogik::starteServerSocket() {
    connect(&serverSocket, SIGNAL(playerJoined(PlayerJoinPacket, unsigned int)), this, SLOT(spieler_beitritt(PlayerJoinPacket, unsigned int)));
    connect(&serverSocket, SIGNAL(playerFinished(PlayerFinishedPacket, unsigned int)), this, SLOT(bekommt_playerFinished(PlayerFinishedPacket, unsigned int)));
    connect(&serverSocket, SIGNAL(answersSent(SendAnswersPacket, unsigned int)), this, SLOT(bekommt_antwort(SendAnswersPacket, unsigned int)));
    serverSocket.listen(PORT);
    emit serverBereit();
}

void CLogik::bekommt_antwort(SendAnswersPacket packet, unsigned int id){

    for(int i = 0; i < m_players.size(); i++){

        if(m_players[i].getConnectionId() == id)
            m_players[i].setAnswers(packet.getAnswers());
    }

    m_answersReceived++;

    if(m_answersReceived == m_players.size()){
        punktevergabe();
        m_answersReceived = 0;
    }
}

void CLogik::spieler_beitritt(PlayerJoinPacket packet, unsigned int id){

    //tell every player another player has joined
    for(int i = 0; i < m_players.size(); ++i ) {

        //reroute PlayerJoinPacket containing new player's name
        serverSocket.send(m_players[i].getConnectionId(), packet);
    }

    Spieler spieler(packet.getName());

    PlayerListPacket playerListPacket;
    QVector <QString> vorherigeSpieler(m_players.size());

    //if needed send list of players to new player
    for (unsigned int var = 0; var < m_players.size(); ++var) {
       vorherigeSpieler[var] = m_players[var].getName();
    }

    playerListPacket.setPlayers(vorherigeSpieler);

    serverSocket.send(id, playerListPacket);

    //add player to private vector of player objects
    spieler.setConnectionId(id);
    m_players.push_back(spieler);
    if( warteRaum != nullptr ) warteRaum->showPlayer();
}

void CLogik::endGame(){
   EndGamePacket packet;

   //pack ranking vectors (both names and points) in EndGamePacket
   packet = getWinner();

   sendToAll(packet);
}

QVector<QString> CLogik::sortAnswers(unsigned int category) {
    int anzahl = m_players.size();
    QVector<QString> antwortenKategorie;

    //get the answer from every player for "category" and save in vector<string>
    for (int var = 0; var < anzahl; ++var) {
        antwortenKategorie.push_back(m_players[var].getAnswer(category));
    }

   return antwortenKategorie;
}

void CLogik::punktevergabe(){
    unsigned int categories = m_players[0].Categories();

    //for every category
    //fill vector with answers for that category and save in an object of antworten
    //save the object antworten in private vector m_answers
    for (unsigned int var = 0;var < categories; ++var) {
        m_answers.push_back(sortAnswers(var));
    }

    //for every category
    //fill vector with points for that category and save in an object of punkte
    //save the object punkte in private vector m_points
    for (unsigned int n = 0; n < categories; ++n){
        m_points.push_back(awardPoints(n));
    }

    int anzahl = m_players.size();

    //for every player
    for (int m = 0; m < anzahl; ++m){
        Spieler player = m_players.at(m);
        SendPointsPacket packet;
        int speicher = 0;

        //add up the points player received for this round
        for (int var = 0; var < categories; ++var) {
            player.credits.push_back(m_points[var].getEinenPunkt(m));
            speicher = speicher +m_points[var].getEinenPunkt(m);
        }

        //get total points up to this round and add up points for this round
        int jetzt = player.getPunkte();
        player.setPunkte(jetzt + speicher);

        //fill SendPointsPacket and send to player
        packet.setPoints(player.getCredit());
        packet.setTotalPoints(player.getPunkte());
        serverSocket.send(player.getConnectionId(), packet);

        //update player object in server logic
        m_players.replace(m, player);
    }

    //start waiting time inbetween rounds
    roundTimer->rundenPausenTimer();

    //clear up private vectors in preparation for next round
    m_points.clear();
    m_answers.clear();
}


QVector<int> CLogik::awardPoints(unsigned int category){
    //get answers for this category
    QVector<QString> antworten = m_answers[category].getAntworten();
    int anzahl = m_players.size();
    QVector<int> points;
    int sum = 0;

    //for every player
    for (int var = 0; var < anzahl; ++var) {
        //if answer is empty or starts with the wrong letter
        if (antworten[var] == "" || (antworten[var][0] != m_letter && antworten[var][0] != toupper(m_letter))){
            points.push_back(0);
        }
        else {
            points.push_back(10);
        }

        //if somebody else has the same solution
        for (int n = 0; n < anzahl; ++n) {
            if (n != var && antworten[var] == antworten [n] &&( antworten[var][0] == m_letter || antworten[var][0] == toupper(m_letter)))

                    points.replace(var, 5);
        }
    }

    //sum = total points given for this category
    for (int z = 0; z < anzahl; ++z){
        sum = sum + points.at(z);
    }

    //if only one person has a correct answer = if only one person has points for that category
    for (int v = 0; v < anzahl; ++v){
        if (sum > 0 && sum == points.at(v) && (antworten[v][0] == m_letter || antworten[v][0] == toupper(m_letter))){
            points.replace(v,20);
        }
    }

    return points;
}


EndGamePacket CLogik::getWinner() {
    int anzahl = m_players.size();

    QVector<QString> names;
    QVector<int> allPoints;
    QVector<unsigned int> ids;

    // Save points of all players in allPoints
    for (int var = 0; var < anzahl; ++var) {
        allPoints.push_back(m_players[var].getPunkte());
    }

    //not yet sorted
    bool sorted = false;

    while(!sorted){

        // when no swap needed in for loop, array is sorted
        sorted = true;

        // For all players
        for (int i = 0;i < anzahl; ++i) {

            // When not last element and current points less than next points
            // then swap current and next points (bubble sort like), set status to unsorted
            if ( (i+1<anzahl) && (allPoints[i] < allPoints[i+1]) ){
                int temp = allPoints[i];
                allPoints[i] = allPoints[i+1];
                allPoints[i+1] = temp;
                sorted = false;
            }

        }

    }

    // For each rank
    for (int n = 0; n < anzahl; ++n) {

        // Check points for every player
        for (int p = 0; p < anzahl; ++p){

            //If allPoints equal the player's total points
            // add player's connection id to list
            if (allPoints[n] == m_players[p].getPunkte())
                ids.push_back(m_players[p].getConnectionId());

            //if connection ids match
            //fill name vector with the player's name
            if(ids[n] == m_players[p].getConnectionId())
                names.push_back(m_players[p].getName());
        }

    }

    //fill EndGamePacket with the sorted vectors
    EndGamePacket packet(names, allPoints);
    return packet;
}

char CLogik::getLetter(){
    //if the last position in the m_usedLetters array is occupied clear array
    if (m_usedLetters[25] != 0x00){
        for (int var = 0; var < 26; ++var) {
            m_usedLetters[var] = 0x00;
        }
    }

    char letter;
    bool success = false;

    while(!success){
    //chose is a random number between 0 and 25
    int choose = rand() % 26;
    success = true;

    letter = m_letters[choose];

    //check if letter is already in m_usedLetters
    for (int var = 0; var < 26; ++var) {
        if (m_usedLetters[var] == letter){
            success = false;
        }
        else if(m_usedLetters[var] == 0x00){
            m_usedLetters[var] = letter;
            break;
        }
    }

    //update private m_letter
    m_letter = letter;

    }

    return letter;
}

Spieleinstellungen* CLogik::getSpieleinstellungen()
{
    return &m_einstellung;
}

QVector<Spieler>* CLogik::getSpielerListe()
{
    return &m_players;
}

void CLogik::openHostSpielEinstellungen()
{
    HostSpielEinstellungen einstellungen(nullptr, this);
    einstellungen.exec();
}
 void CLogik::openKategorieEingabe()
 {
     Kategorieeingabe eingabe(nullptr, this);
     eingabe.exec();
 }
 void CLogik::openSpielerWarteRaum()
 {
    starteServerSocket();
     warteRaum = new SpielerWarteRaum(nullptr,this);
     warteRaum->exec();
 }

 void CLogik::sendToAll(Packet& p){
     for(int i = 0; i < m_players.size(); i++){
         serverSocket.send(m_players[i].getConnectionId(), p);
     }
 }

 void CLogik::sendeSpielStart(){
     PlayerListPacket listPacket;
     QVector<QString> namen;

     //fill namen with the players' names
     for(int i = 0; i < m_players.size(); i++){
        namen.push_back(m_players[i].getName());
     }

     listPacket.setPlayers(namen);
     GameSettingsPacket packet(this->getSpieleinstellungen()->getSpielname(), this->getSpieleinstellungen()->getRundenanzahl(), this->getSpieleinstellungen()->getRundendauer(), this->getSpieleinstellungen()->getCountdown(), this->getSpieleinstellungen()->getKategorienListe());
     sendToAll(packet);
     sendToAll(listPacket);
     roundTimer = new timer(this->getSpieleinstellungen()->getRundendauer(), 3, this->getSpieleinstellungen()->getCountdown());
     setupTimer();
 }

void CLogik::sendeRundenStart(){
    //if the maximum number of rounds has not been reached
    if(m_currentRound < getSpieleinstellungen()->getRundenanzahl())
    {   StartCountdownPacket packet;
        sendToAll(packet);
        roundTimer->startRound();
        qDebug() << "RundenStart :))";
        //update private m_currentRound
        m_currentRound++;
    }
    else{
        //get ranking and initialise end of game
        EndGamePacket endPacket;
        endPacket = getWinner();
        sendToAll(endPacket);
        qDebug() << "Spiel fertig";
    }
}

void CLogik::nextRound(){
    sendeRundenStart();
}

 void CLogik::setupTimer(){
    QObject::connect(roundTimer, SIGNAL(signalStartInput()), this, SLOT(startInput()));
    QObject::connect(roundTimer, SIGNAL(signalPlayerFinished()), this, SLOT(playerFinished()));
    QObject::connect(roundTimer, SIGNAL(signalRoundOver()), this, SLOT(endInput()));
    QObject::connect(this, SIGNAL(initRoundEnd()), roundTimer, SLOT(receivedPlayerFinished()));
    QObject::connect(roundTimer, SIGNAL(pausenTimer()), this, SLOT(nextRound()));
 }

 void CLogik::startInput(){
     //get random letter and initialise round start
     RoundStartPacket packet(getLetter());
     sendToAll(packet);
 }

 void CLogik::playerFinished(){
    PlayerFinishedPacket packet;
    sendToAll(packet);

 }

 void CLogik::endInput(){
    EndRoundPacket packet;
    sendToAll(packet);
 }

 void CLogik::bekommt_playerFinished(PlayerFinishedPacket Packet, unsigned int id){
     emit initRoundEnd();
 }

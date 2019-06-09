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

    for(int i = 0; i < players.size(); i++){

        if(players[i].getConnectionId() == id)
            players[i].setAnswers(packet.getAnswers());
    }

    answersReceived++;

    if(answersReceived == players.size()){
        Punktevergabe();
        answersReceived = 0;
    }
}

void CLogik::spieler_beitritt(PlayerJoinPacket packet, unsigned int id){

    // Jedem aktuell gespeichert Spieler mitteilen, dass ein neuer Spieler beigetreten ist:
    // Einmal den Spieler Vektor durchgehen
    for(int i = 0; i < players.size(); ++i ) {

        // Client braucht ein PlayerJoinPacket mit dem Name des Spielers
        // Das Paket, das der Server bekommt enth?lt den Namen des Spielers, wir k?nnen es direkt weiterleiten
        serverSocket.send(players[i].getConnectionId(), packet);
    }

    Spieler spieler(packet.getName());

    PlayerListPacket playerListPacket;
    QVector <QString> vorherigeSpieler(players.size());

    //evtl aktuelle Spielerliste an neuen Spieler leiten
    for (unsigned int var = 0; var < players.size(); ++var) {
       vorherigeSpieler[var] = players[var].getName();
    }

    playerListPacket.setPlayers(vorherigeSpieler);

    serverSocket.send(id, playerListPacket);
    spieler.setConnectionId(id);
    players.push_back(spieler);
    if( warteRaum != nullptr ) warteRaum->showPlayer();


}

void CLogik::endGame(){
   EndGamePacket packet;

   packet = getWinner();

   for (unsigned int var = 0; var < players.size(); ++var) {
       serverSocket.send(players[var].getConnectionId(), packet);
   }

}

int CLogik::createPlayer(QString name) {

    Spieler spieler(name);

    players[spieler.getId()] = spieler;
    return spieler.getId();
}

QVector<QString> CLogik::sortAnswers(unsigned int category) {
    int anzahl = players.size();
    QVector<QString> antwortenKategorie;

    for (int var = 0; var < anzahl; ++var) {
        antwortenKategorie.push_back(players[var].getAnswer(category));
    }

   return antwortenKategorie;
}

void CLogik::Punktevergabe(){
    unsigned int categories = players[0].Categories();

    for (unsigned int var = 0;var < categories; ++var) {
        m_answers.push_back(sortAnswers(var));
    }

    for (unsigned int n = 0; n < categories; ++n){
        m_points.push_back(awardPoints(n));
    }

    int anzahl = players.size();

    for (int m = 0; m < anzahl; ++m){
        Spieler player = players.at(m);
        SendPointsPacket packet;
        int speicher = 0;

        for (int var = 0; var < categories; ++var) {
            player.credits.push_back(m_points[var].getEinenPunkt(m));
            speicher = speicher +m_points[var].getEinenPunkt(m);
        }

        int jetzt = player.getPunkte();
        player.setPunkte(jetzt + speicher);

        packet.setPoints(player.getCredit());
        packet.setTotalPoints(player.getPunkte());


        serverSocket.send(player.getConnectionId(), packet);
        players.replace(m, player);
    }
    roundTimer->rundenPausenTimer();
    m_points.clear();
    m_answers.clear();
}


QVector<int> CLogik::awardPoints(unsigned int category){
    qDebug() << "ich bin in awardPoints für Kategorie" << category << endl;
    QVector<QString> antworten = m_answers[category].getAntworten();
    int anzahl = players.size();
    QVector<int> points;
    int sum = 0;

    for (int var = 0; var < anzahl; ++var) {
        if (antworten[var] == "" || (antworten[var][0] != m_letter && antworten[var][0] != toupper(m_letter))){
            points.push_back(0);
        }
        else {
            points.push_back(10);
        }

        for (int n = 0; n < anzahl; ++n) {
            if (n != var && antworten[var] == antworten [n] &&( antworten[var][0] == m_letter || antworten[var][0] == toupper(m_letter)))

                    points.replace(var, 5);
        }
    }

    // total points which are given for all players in this category
    for (int z = 0; z < anzahl; ++z){
        sum = sum + points.at(z);
    }

    for (int v = 0; v < anzahl; ++v){
        if (sum > 0 && sum == points.at(v) && (antworten[v][0] == m_letter || antworten[v][0] == toupper(m_letter))){
            points.replace(v,20);
        }
    }

    return points;
}


EndGamePacket CLogik::getWinner() {
    qDebug() << "getWinner: " << players.size() << endl;
    int anzahl = players.size();

    QVector<QString> names;
    QVector<int> allPoints;

    // Save points of all players in allPoints
    for (int var = 0; var < anzahl; ++var) {
        allPoints.push_back(players[var].getPunkte());
    }
    bool sorted = false;

    while(!sorted){

        // when no swap needed in for loop, array is sorted
        sorted = true;
        qDebug() << "Feli ist in der While Schleife" << endl;

        // For all players
        for (int i = 0;i < anzahl; ++i) {
            qDebug() << " in der for Schleife ist i " << i << endl;

            // When not last element and current points less than next points
            // -> swap current and next points (bubble sort like), set status to unsorted
            if ( (i+1<anzahl) && (allPoints[i] < allPoints[i+1]) ){
                int temp = allPoints[i];
                allPoints[i] = allPoints[i+1];
                allPoints[i+1] = temp;
                qDebug() << "in se if drinne " << i << endl;
                sorted = false;
            }

        }

    }
    qDebug() << "Zwischenstelle 0" << endl;

    // For each rank
    for (int n = 0; n < anzahl; ++n) {

        // Check points for every player
        for (int p = 0; p < anzahl; ++p){

            // When actual points to check equals points of player
            // -> add player to list
            if (allPoints[n] == players[p].getPunkte()){//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                names.push_back(players[p].getName());
                qDebug() << "in se sekond if drinne " << n << endl;
            }
        }


    }
    qDebug() << names << endl;
    qDebug() << allPoints << endl;
    EndGamePacket packet(names, allPoints);
    return packet;
}

char CLogik::getLetter(){
    if (usedLetters[25] != 0x00){
        for (int var = 0; var < 26; ++var) {
            usedLetters[var] = 0x00;
        }
    }
    else {
        //do nothing
    }

    char letter;
    bool success = false;

    while(!success) {
        int choose = rand() % 26;
        success = true;
        letter = letters[choose];

        // Check every entry in usedLetters
        for (int var = 0; var < 26; ++var) {

            // when actual letter equals entry in usedLetters
            if (usedLetters[var] == letter){
                success = false;
                break;
            }
            else if(usedLetters[var] == 0x00){
                usedLetters[var] = letter;
                break;
            }
        }

        m_letter = letter;

    }

    return letter;
}
Spieleinstellungen* CLogik::getSpieleinstellungen()
{
    return &_einstellung;
}

QVector<Spieler>* CLogik::getSpielerListe()
{
    return &players;
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
     for(int i = 0; i < players.size(); i++){
         serverSocket.send(players[i].getConnectionId(), p);
     }
 }

 void CLogik::sendeSpielStart(){
     PlayerListPacket listPacket;
     QVector<QString> namen;
     for(int i = 0; i < players.size(); i++){
        namen.push_back(players[i].getName());
     }
     listPacket.setPlayers(namen);
     GameSettingsPacket packet(this->getSpieleinstellungen()->getSpielname(), this->getSpieleinstellungen()->getRundenanzahl(), this->getSpieleinstellungen()->getRundendauer(), this->getSpieleinstellungen()->getCountdown(), this->getSpieleinstellungen()->getKategorienListe());
     sendToAll(packet);
     sendToAll(listPacket);
     roundTimer = new timer(this->getSpieleinstellungen()->getRundendauer(), 3, this->getSpieleinstellungen()->getCountdown());
     setupTimer();
 }

void CLogik::sendeRundenStart(){
    if(currentRound < getSpieleinstellungen()->getRundenanzahl())
    {   StartCountdownPacket packet;
        sendToAll(packet);
        roundTimer->startRound();
        qDebug() << "RundenStart :))";
        currentRound++;
    }else{
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

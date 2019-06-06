#include "CLogik.h"
#include "spieler.h"
#include "antworten.h"
#include "punkte.h"
#include "hostspieleinstellungen.h"
#include "spielerwarteraum.h"
#include "kategorieeingabe.h"

CLogik::CLogik() : warteRaum(nullptr) {
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
    serverSocket.listen(PORT);
    emit serverBereit();
}

void CLogik::bekommt_antwort(SendAnswersPacket packet, unsigned int id){
    for(int i = 0; i < players.size(); i++){

        if(players[i].getConnectionId() == id){
            players[i].setAnswers(packet.getAnswers());
        }else{
            serverSocket.send(players[i].getConnectionId(), packet);
        }
    }
}

void CLogik::spieler_beitritt(PlayerJoinPacket packet, unsigned int id){

    // Jedem aktuell gespeichert Spieler mitteilen, dass ein neuer Spieler beigetreten ist:
    // Einmal den Spieler Vektor durchgehen
    for(int i = 0; i < players.size(); ++i ) {

        // Client braucht ein PlayerJoinPacket mit dem Name des Spielers
        // Das Paket, das der Server bekommt enthält den Namen des Spielers, wir können es direkt weiterleiten
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
    qDebug() << spieler.getName() << " hat sich verbunden" << endl;

    warteRaum->showPlayer();
    /*qDebug() << "Spieler beigetreten";

    for (unsigned int var = 0; var < players.size(); ++var) {
        std::cout << players[var].getName() << std::endl;
    }*/

}

void CLogik::endGame(){
   EndGamePacket packet;

   packet.setRanking(getWinner());

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
    unsigned int anzahl = players.size();
    QVector<QString> antwortenKategorie;

    for (unsigned int var = 0; var < anzahl; ++var) {
        antwortenKategorie[var] = players[var].getAnswer(category);
    }

   return antwortenKategorie;
}

void CLogik::Punktevergabe(){
    unsigned int categories = players[0].Categories();

    for (unsigned int var = 0;var < categories; ++var) {
        answers[var]= sortAnswers(var);
    }

    for (unsigned int n = 0; n < categories; ++n){
        points[n] = awardPoints(n);
    }

    unsigned int anzahl = players.size();

    for (unsigned int m = 0; m < anzahl; ++m){
        Spieler player = players[m];
        SendPointsPacket packet;

        int speicher = 0;

        for (unsigned int l = 0; l < categories; ++l){
            QVector<int> punkte = points[l].getPunkte();
            player.setCredit(l, punkte[l]);
            speicher = speicher + punkte[l];
        }

        int jetzt = player.getPunkte();
        player.setPunkte(jetzt + speicher);

        packet.setPoints(player.getCredit());
        packet.setTotalPoints(player.getPunkte());

        serverSocket.send(player.getConnectionId(), packet);
    }


}


QVector<int> CLogik::awardPoints(unsigned int category){
    QVector<QString> antworten = answers[category].getAntworten();
    unsigned int anzahl = antworten.size();
    QVector<int> points;
    int sum = 0;

    for (unsigned int var = 0; var < anzahl; ++var) {
        if (antworten[var] == "" || antworten[var][0] != m_letter){
            points[var] = 0;
        }
        else {
            points[var] = 10;
        }
        for (unsigned int n = 0; n < anzahl; ++n) {
            if (n != var && antworten[var] == antworten [n]){
                    points[var] = 5;
                }                            
            else {
                //do nothing - same player or different answers
            }
        }
    }

    for (unsigned int v = 0; v < anzahl; ++v){
        for (unsigned int z = 0; z < anzahl; ++z){
            sum = sum + points[z];
        }
        if (sum == points[v]){
            points[v] = 20;
        }
    }

    return points;
}


QVector<QString> CLogik::getWinner() {
    unsigned int anzahl = players.size();
    QVector<QString> names;
    QVector<int> allPoints;

    for (unsigned int var = 0; var < anzahl; ++var) {
        allPoints[var] = players[var].getPunkte();
    }

    bool sorted = false;

    while(!sorted){
        sorted = true;

        for (unsigned int i = 0;i < anzahl; ++i) {

            if (allPoints[i]<allPoints[i+1]){
                int temp = allPoints[i];
                allPoints[i] = allPoints[i+1];
                allPoints[i+1] = temp;
            }

            sorted = false;
        }
    }

    for (unsigned int n = 0; n < anzahl; ++n) {
        for (unsigned int p = 0; p < anzahl; ++p){
            if (allPoints[n] = players[p].getPunkte()){
                names[n] = players[p].getName();
            }
        }


    }
    return names;
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

    while(!success){
    int choose = rand() % 26;
    success = true;
    letter = letters[choose];

    for (int var = 0; var < 26; ++var) {
        if (usedLetters[var] == letter){
            success = false;
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

 void CLogik::sendeSpielStart(){

     GameSettingsPacket Packet(this->getSpieleinstellungen()->getSpielname(), this->getSpieleinstellungen()->getRundenanzahl(), this->getSpieleinstellungen()->getRundendauer(), this->getSpieleinstellungen()->getCountdown(), this->getSpieleinstellungen()->getKategorienListe());
     PlayerListPacket playerListPacket;
     QVector <QString> vorherigeSpieler(players.size());

     //evtl aktuelle Spielerliste an neuen Spieler leiten
     for (unsigned int var = 0; var < players.size(); ++var) {
        vorherigeSpieler[var] = players[var].getName();
     }

     playerListPacket.setPlayers(vorherigeSpieler);


     for(unsigned int i = 0; i < players.size(); i++){
         serverSocket.send(players[i].getConnectionId(), Packet);
         serverSocket.send(players[i].getConnectionId(), playerListPacket);
     }
     roundTimer = new timer(this->getSpieleinstellungen()->getRundendauer(), 3, this->getSpieleinstellungen()->getCountdown());
 }

 void CLogik::sendeRundenStart(){
     RoundStartPacket packet(getLetter());
     for(unsigned int i = 0; i < players.size(); i++){

         serverSocket.send(players[i].getConnectionId(), packet);

     }
     this->roundTimer->startRound();
 }
 void CLogik::setupTimer(){

 }

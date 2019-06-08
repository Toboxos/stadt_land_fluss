#include "clientlogic.h"
#include "spielstart.h"
#include "CLogik.h"
#include "clientipeingabe.h"
#include "hauptspielfenster.h"
#include <QDebug>
ClientLogic::ClientLogic() : _clogik(nullptr), _hautpSpielFenster(nullptr)
{
    SpielStart spielstart(nullptr, this);
     spielstart.exec();
}

ClientLogic::~ClientLogic() {
    delete _clogik;
    delete _hautpSpielFenster;
}
void ClientLogic::setAnswerVector(QVector<QString> answerVector)
{
    _answerVector = answerVector;
}
void ClientLogic::connect(QString name, QString ip, quint16 port, ClientIpEingabe *window)
{

    _clientSocket.connectTo(ip,port);
   QObject::connect(&_clientSocket, SIGNAL(receivedGameSettings(GameSettingsPacket)), this, SLOT(starteSpiel(GameSettingsPacket)));
   QObject::connect(&_clientSocket, SIGNAL(playerJoined(PlayerJoinPacket)), this, SLOT(playerJoinedSlot(PlayerJoinPacket)));
   QObject::connect(&_clientSocket, SIGNAL(receivedPlayerList(PlayerListPacket)), this, SLOT(receivedPlayerListSlot(PlayerListPacket)));
   QObject::connect(&_clientSocket, SIGNAL(startCountdown(StartCountdownPacket)), this, SLOT(receivedStartCountdown(StartCountdownPacket)));
   QObject::connect(&_clientSocket, SIGNAL(roundStart(RoundStartPacket)), this, SLOT(receivedRoundStart(RoundStartPacket)));
   QObject::connect(&_clientSocket, SIGNAL(endRound(EndRoundPacket)), this, SLOT(receivedRoundEnd(EndRoundPacket)));
   QObject::connect(&_clientSocket, SIGNAL(playerFinished(PlayerFinishedPacket)), this, SLOT(playerFinished(PlayerFinishedPacket)));
   QObject::connect(&_clientSocket, SIGNAL(timeout()), this, SLOT(timeoutSlot()));
   QObject::connect(&_clientSocket, SIGNAL(connected()), this, SLOT(connectedSlot()));
   QObject::connect(&_clientSocket, SIGNAL(error()), this, SLOT(errorSlot()));
   QObject::connect(&_clientSocket, SIGNAL(pointsSent(SendPointsPacket)), this, SLOT(receivedPoints(SendPointsPacket)));
   if( window != nullptr ) QObject::connect(&_clientSocket, SIGNAL(connected()), window, SLOT(connected()));
}

void ClientLogic::receivedPoints(SendPointsPacket Packet){
    clientSpieler.credits.clear();
    clientSpieler.setPunkte(Packet.getTotalPoints());

    for (int var = 0;var < Packet.getPoints().size();++var) {
        clientSpieler.credits.push_back(Packet.getPoints()[var]);    
    }
    qDebug() << clientSpieler.credits << "Punkte von Spieler" << clientSpieler.getName() << endl;
    _hautpSpielFenster->setTotalPoints(clientSpieler.getPunkte());
}

void ClientLogic::openCLogik() {
    _clogik  = new CLogik();
    QObject::connect(_clogik, SIGNAL(serverBereit()), this, SLOT(serverBereit()));
    _clogik->run();
}

void ClientLogic::serverBereit() {
    connect(clientSpieler.getName(), "localhost", PORT, nullptr);
}

void ClientLogic::sendAnswers(){
    _hautpSpielFenster->fillAnswerVector();
    clientSpieler.setAnswers(_hautpSpielFenster->getAnserVector());

    SendAnswersPacket packet(clientSpieler.answers);

    _clientSocket.send(packet);
    _hautpSpielFenster->clearAnswerVector();
}

void ClientLogic::playerJoinedSlot(PlayerJoinPacket Packet){
    this->_spielerListe.push_back(Packet.getName());
    //Anzeige!
}

void ClientLogic::receivedPlayerListSlot(PlayerListPacket Packet){
    for (unsigned int var = 0; var < Packet.getPlayers().size(); ++var) {
        this->_spielerListe.push_back(*new Spieler(Packet.getPlayers()[var]));
    }

    if( _hautpSpielFenster != nullptr ) {
        _hautpSpielFenster->setPlayers(Packet.getPlayers(), clientSpieler.getName());
    }
    //Anzeigen??
}

void ClientLogic::receivedStartCountdown(StartCountdownPacket packet){
    qDebug() << "Runde startet in 3 Sekunden";
    _hautpSpielFenster->startCountdown();
    //_hautpSpielFenster->newRow();
    //_hautpSpielFenster->update();

}

void ClientLogic::receivedRoundEnd(EndRoundPacket Packet){
    sendAnswers();
    _hautpSpielFenster->newRow();
    qDebug() << "Runde ist beendet, receivedRoundEnd";
}

void ClientLogic::timeoutSlot(){
    //timeout
    qDebug() << "Timeout :((" << endl;

}
void ClientLogic::connectedSlot(){
    PlayerJoinPacket playerJoinPacket(this->getSpieler().getName());
    _clientSocket.send(playerJoinPacket);
    qDebug() << "connected :))" << endl;
}
void ClientLogic::errorSlot(){
    //error
    qDebug() << "Error :(((" << endl;
}
void ClientLogic::openClientIpEingabe()
{
    ClientIpEingabe ClientStart(nullptr,this);
    ClientStart.exec();
}

void ClientLogic::openHauptSpielFenster(){
    _hautpSpielFenster = new HauptSpielFenster();
    QObject::connect(_hautpSpielFenster, SIGNAL(fertig()), this, SLOT(fensterFertig()));

    _hautpSpielFenster->show();
}

Spieler ClientLogic::getSpieler(){
    return clientSpieler;
}
void ClientLogic::setSpieler(Spieler spieler){
    clientSpieler = spieler;
}

void ClientLogic::playerFinished(PlayerFinishedPacket Packet){
    qDebug() << "Nur noch zehn Sekunden, beeile dich!";
}

void ClientLogic::starteSpiel(GameSettingsPacket Packet){
    _einstellung.setCountdown(Packet.getCountown());
    _einstellung.setPlayName(Packet.getGameName());
    _einstellung.setRoundNumber(Packet.getRoundNumbers());
    _einstellung.setRoundTimeLimit(Packet.getRoundDuration());
    _einstellung.setKategories(Packet.getCategories());
    openHauptSpielFenster();
    _hautpSpielFenster->setCategories(Packet.getCategories());
}

void ClientLogic::fensterFertig() {
PlayerFinishedPacket packet(getSpieler().getName());
_clientSocket.send(packet);
}
void ClientLogic::receivedRoundStart(RoundStartPacket Packet){
    _hautpSpielFenster->setLetter(Packet.getLetter());
}

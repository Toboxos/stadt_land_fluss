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

void ClientLogic::connect(QString name, QString ip, quint16 port, ClientIpEingabe *window)
{

    _clientSocket.connectTo(ip,port);
   QObject::connect(&_clientSocket, SIGNAL(receivedGameSettings(GameSettingsPacket)), this, SLOT(starteSpiel(GameSettingsPacket)));
   QObject::connect(&_clientSocket, SIGNAL(playerJoined(PlayerJoinPacket)), this, SLOT(playerJoinedSlot(PlayerJoinPacket)));
   QObject::connect(&_clientSocket, SIGNAL(receivedPlayerList(PlayerListPacket)), this, SLOT(receivedPlayerListSlot(PlayerListPacket)));
   QObject::connect(&_clientSocket, SIGNAL(timeout()), this, SLOT(timeoutSlot()));
   QObject::connect(&_clientSocket, SIGNAL(connected()), this, SLOT(connectedSlot()));
   QObject::connect(&_clientSocket, SIGNAL(error()), this, SLOT(errorSlot()));
   if( window != nullptr ) QObject::connect(&_clientSocket, SIGNAL(connected()), window, SLOT(connected()));
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
    SendAnswersPacket packet(clientSpieler.answers);
    _clientSocket.send(packet);
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
    _hautpSpielFenster = new HauptSpielFenster(nullptr);
    _hautpSpielFenster->show();
}

Spieler ClientLogic::getSpieler(){
    return clientSpieler;
}
void ClientLogic::setSpieler(Spieler spieler){
    clientSpieler = spieler;
}

void ClientLogic::done(){
    sendAnswers();
    PlayerFinishedPacket packet;
    _clientSocket.send(packet);
}

void ClientLogic::starteSpiel(GameSettingsPacket Packet){
    this->_einstellung.setCountdown(Packet.getCountown());
    this->_einstellung.setPlayName(Packet.getGameName());
    this->_einstellung.setRoundNumber(Packet.getRoundNumbers());
    this->_einstellung.setRoundTimeLimit(Packet.getRoundDuration());
    this->_einstellung.setKategories(Packet.getCategories());
    this->openHauptSpielFenster();
    _hautpSpielFenster->setCategories(Packet.getCategories());
}

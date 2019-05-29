#include "clientlogic.h"
#include "spielstart.h"
ClientLogic::ClientLogic()
{
    SpielStart spielstart(nullptr, this);
     spielstart.exec();
}

void ClientLogic::connect(QString name, QString ip, quint16 port)
{
    _clientSocket.connectTo(ip,port);
   PlayerJoinPacket playerJoinPacket(name);
   _clientSocket.send(playerJoinPacket);
   QObject::connect(&_clientSocket, SIGNAL(playerJoined(PlayerJoinPacket)), this, SLOT(playerJoinedSlot(PlayerJoinPacket)));
   QObject::connect(&_clientSocket, SIGNAL(receivedPlayerList(PlayerListPacket)), this, SLOT(receivedPlayerListSlot(PlayerListPacket)));
   QObject::connect(&_clientSocket, SIGNAL(timeout()), this, SLOT(timeoutSlot()));
   QObject::connect(&_clientSocket, SIGNAL(connected()), this, SLOT(connectedSlot()));
   QObject::connect(&_clientSocket, SIGNAL(error()), this, SLOT(errorSlot()));
}
Spieleinstellungen* ClientLogic::getSpieleinstellungen()
{
    return &_einstellung;
}
std::vector<Spieler>* ClientLogic::getSpielerListe()
{
    return &_spielerListe;
}
void ClientLogic::playerJoinedSlot(PlayerJoinPacket Packet){
    this->getSpielerListe()->push_back(Packet.getName().toStdString());
}
void ClientLogic::receivedPlayerListSlot(PlayerListPacket Packet){
//    this->getSpielerListe() = Packet.getPlayers(); QVector zu vector Problem
}
void ClientLogic::timeoutSlot(){
    //timeout
}
void ClientLogic::connectedSlot(){
    //connected
}
void ClientLogic::errorSlot(){
    //error
}

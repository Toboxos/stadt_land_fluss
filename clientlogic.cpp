#include "clientlogic.h"
#include "spielstart.h"
#include "CLogik.h"
#include "clientipeingabe.h"
ClientLogic::ClientLogic()
{

    SpielStart spielstart(nullptr, this);
     spielstart.exec();
}

void ClientLogic::connect(QString name, QString ip, quint16 port)
{
    _clientSocket.connectTo(ip,port);

   QObject::connect(&_clientSocket, SIGNAL(playerJoined(PlayerJoinPacket)), this, SLOT(playerJoinedSlot(PlayerJoinPacket)));
   QObject::connect(&_clientSocket, SIGNAL(receivedPlayerList(PlayerListPacket)), this, SLOT(receivedPlayerListSlot(PlayerListPacket)));
   QObject::connect(&_clientSocket, SIGNAL(timeout()), this, SLOT(timeoutSlot()));
   QObject::connect(&_clientSocket, SIGNAL(connected()), this, SLOT(connectedSlot()));
   QObject::connect(&_clientSocket, SIGNAL(error()), this, SLOT(errorSlot()));
}



void ClientLogic::openCLogik()
{
    CLogik *_cLogic  = new CLogik();
}
void ClientLogic::playerJoinedSlot(PlayerJoinPacket Packet){
//    this->getSpielerListe()->push_back(Packet.getName().toStdString());
}
void ClientLogic::receivedPlayerListSlot(PlayerListPacket Packet){
//    this->getSpielerListe() = Packet.getPlayers(); QQVector zu QVector Problem
}
void ClientLogic::timeoutSlot(){
    //timeout
}
void ClientLogic::connectedSlot(){
    PlayerJoinPacket playerJoinPacket("hilfegard");
    _clientSocket.send(playerJoinPacket);
}
void ClientLogic::errorSlot(){
    //error
}
void ClientLogic::openClientIpEingabe()
{
    ClientIpEingabe ClientStart(nullptr,this);
    ClientStart.exec();
}
Spieler ClientLogic::getSpieler(){
    return *clientSpieler;
}
void ClientLogic::setSpieler(Spieler *spieler){
    clientSpieler = spieler;
}


#include "clientlogic.h"
#include "spielstart.h"
#include "CLogik.h"
#include "clientipeingabe.h"
#include "hauptspielfenster.h"
#include <QDebug>
ClientLogic::ClientLogic()
{

    SpielStart spielstart(nullptr, this);
     spielstart.exec();
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
   QObject::connect(&_clientSocket, SIGNAL(connected()), window, SLOT(connected()));
   PlayerJoinPacket playerJoinPacket(this->getSpieler().getName());
   _clientSocket.send(playerJoinPacket);
}


void ClientLogic::openCLogik()
{
    CLogik *_cLogic  = new CLogik();
}
void ClientLogic::playerJoinedSlot(PlayerJoinPacket Packet){
    qDebug() << "playerJoinedSlot" << endl;
//    this->getSpielerListe()->push_back(Packet.getName().toStdString());
}
void ClientLogic::receivedPlayerListSlot(PlayerListPacket Packet){
//    this->getSpielerListe() = Packet.getPlayers(); QQVector zu QVector Problem
    qDebug() << "receivedPlayerList" << endl;
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
    HauptSpielFenster SpielStart(nullptr, this);
    SpielStart.show();
}

Spieler ClientLogic::getSpieler(){
    return *clientSpieler;
}
void ClientLogic::setSpieler(Spieler *spieler){
    clientSpieler = spieler;
}

void ClientLogic::starteSpiel(GameSettingsPacket Packet){
    this->_einstellung.setCountdown(Packet.getCountown());
    this->_einstellung.setPlayName(Packet.getGameName());
    this->_einstellung.setRoundNumber(Packet.getRoundNumbers());
    this->_einstellung.setRoundTimeLimit(Packet.getRoundDuration());
    this->_einstellung.setKategories(Packet.getCategories());
    this->openHauptSpielFenster();
}

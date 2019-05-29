#include "clientlogic.h"
#include "spielstart.h"
#include "CLogik.h"
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
}



void ClientLogic::openCLogik()
{
    CLogik *_cLogic  = new CLogik();
}

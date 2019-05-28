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
}
Spieleinstellungen* ClientLogic::getSpieleinstellungen()
{
    return &_einstellung;
}
std::vector<Spieler>* ClientLogic::getSpielerListe()
{
    return &_spielerListe;
}

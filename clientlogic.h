#ifndef CLIENTLOGIC_H
#define CLIENTLOGIC_H
#include "Network/clientsocket.h"
#include "spieleinstellungen.h"
#include "spieler.h"


class ClientLogic
{
public:
    ClientLogic();
    void connect(QString name, QString ip, quint16 port);
    void openCLogik();


private:
    ClientSocket _clientSocket;


};




#endif // CLIENTLOGIC_H

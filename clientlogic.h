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
    Spieleinstellungen* getSpieleinstellungen();
    std::vector<Spieler>* getSpielerListe();

private:
    ClientSocket _clientSocket;
    std::vector<Spieler> _spielerListe;
    Spieleinstellungen  _einstellung ;

};




#endif // CLIENTLOGIC_H

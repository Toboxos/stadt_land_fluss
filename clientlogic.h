#ifndef CLIENTLOGIC_H
#define CLIENTLOGIC_H
#include "Network/clientsocket.h"
#include "spieleinstellungen.h"
#include "spieler.h"


class ClientLogic : public QObject
{
    Q_OBJECT
public:
    ClientLogic();
    void connect(QString name, QString ip, quint16 port);
    void openCLogik();
    void openClientIpEingabe();
    void setSpieler(Spieler *spieler);
    Spieler getSpieler();


private:
    ClientSocket _clientSocket;
    Spieler *clientSpieler;
    std::vector<Spieler> _spielerListe;
    Spieleinstellungen  _einstellung ;
public slots:
    void playerJoinedSlot(PlayerJoinPacket Packet);
    void receivedPlayerListSlot(PlayerListPacket Packet);
    void timeoutSlot();
    void errorSlot();
    void connectedSlot();



};




#endif // CLIENTLOGIC_H

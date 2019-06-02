#ifndef CLIENTLOGIC_H
#define CLIENTLOGIC_H
#include "Network/clientsocket.h"
#include "spieleinstellungen.h"
#include "spieler.h"
class ClientIpEingabe;
class HauptSpielFenster;
class ClientLogic : public QObject
{
    Q_OBJECT
public:
    ClientLogic();
    void connect(QString name, QString ip, quint16 port, ClientIpEingabe *window);
    void openCLogik();
    void openClientIpEingabe();
    void openHauptSpielFenster();
    void setSpieler(Spieler *spieler);
    Spieler getSpieler();


private:
    ClientSocket _clientSocket;

    QVector<Spieler> _spielerListe;
    Spieler *clientSpieler;
    Spieleinstellungen  _einstellung ;
public slots:
    void playerJoinedSlot(PlayerJoinPacket Packet);
    void receivedPlayerListSlot(PlayerListPacket Packet);
    void timeoutSlot();
    void errorSlot();
    void connectedSlot();
    void starteSpiel(GameSettingsPacket Packet);
};




#endif // CLIENTLOGIC_H

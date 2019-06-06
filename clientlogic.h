#ifndef CLIENTLOGIC_H
#define CLIENTLOGIC_H
#include "Network/clientsocket.h"
#include "spieleinstellungen.h"
#include "spieler.h"
#include "Network/Packets/sendanswerspacket.h"
#include "CLogik.h"
#include "hauptspielfenster.h"
#include "Network/Packets/playerfinishedpacket.h"
class ClientIpEingabe;
class ClientLogic : public QObject
{
    Q_OBJECT
public:
    ClientLogic();
    ~ClientLogic();
    void connect(QString name, QString ip, quint16 port, ClientIpEingabe *window);
    void openCLogik();
    void openClientIpEingabe();
    void openHauptSpielFenster();
    void setSpieler(Spieler spieler);
    Spieler getSpieler();
    void sendAnswers();
    void done();
    void setAnswerVector(QVector<QString>);
private:
    ClientSocket _clientSocket;
    CLogik* _clogik;

    HauptSpielFenster* _hautpSpielFenster;

    QVector<Spieler> _spielerListe;
    QVector<QString> _answerVector;

    Spieler clientSpieler;
    Spieleinstellungen  _einstellung ;
public slots:
    void playerJoinedSlot(PlayerJoinPacket Packet);
    void receivedPlayerListSlot(PlayerListPacket Packet);
    void timeoutSlot();
    void errorSlot();
    void connectedSlot();
    void starteSpiel(GameSettingsPacket Packet);
    void serverBereit();
    void fensterFertig();

};




#endif // CLIENTLOGIC_H

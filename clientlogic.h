#ifndef CLIENTLOGIC_H
#define CLIENTLOGIC_H
#include "Network/clientsocket.h"
#include "spieleinstellungen.h"
#include "spieler.h"
#include "Network/Packets/sendanswerspacket.h"
#include "serverlogic.h"
#include "hauptspielfenster.h"
#include "Network/Packets/playerfinishedpacket.h"
#include "Network/Packets/endroundpacket.h"
#include "Network/Packets/startcountdownpacket.h"
#include "Network/Packets/sendpointspacket.h"

class ClientIpEingabe;
class ClientLogic : public QObject
{
    Q_OBJECT
public:

    ClientLogic();
    ~ClientLogic();

    ///
    /// \brief connects signals to slots, connects to server
    /// \param name
    /// \param ip
    /// \param port
    /// \param window
    ///
    void connect(QString name, QString ip, quint16 port, ClientIpEingabe *window);

    ///
    /// \brief create object of CLogic, connect serverBereit, trigger ServerLogic.run
    ///
    void openServerLogic();

    ///
    /// \brief create object of ClientIpEingabe and execute
    ///
    void openClientIpEingabe();

    ///
    /// \brief create object of HauptSpielFenster and open, connect to fensterFertig
    ///
    void openHauptSpielFenster();

    ///
    /// \brief create new object of type player and save as clientSpieler
    /// \param player object
    ///
    void setSpieler(Spieler spieler);

    ///
    /// \brief returns the client's player object
    /// \return clientSpieler
    ///
    Spieler getSpieler();

    ///
    /// \brief gets the player's answer in the game's main window and sends them to the server
    ///
    void sendAnswers();

    ///
    /// \brief sets _answerVector
    /// \param answerVector
    ///
    void setAnswerVector(QVector<QString> answerVector);

private:
    ClientSocket _clientSocket;
    ServerLogic* _ServerLogic;

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
    void receivedEndGame(EndGamePacket Packet);
    void receivedStartCountdown(StartCountdownPacket Packet);
    void receivedRoundStart(RoundStartPacket Packet);
    void receivedRoundEnd(EndRoundPacket Packet);
    void playerFinished(PlayerFinishedPacket Packet);
    void receivedPoints(SendPointsPacket Packet);


};




#endif // CLIENTLOGIC_H

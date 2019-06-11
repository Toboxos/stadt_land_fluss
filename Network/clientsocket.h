#ifndef CLIENTSOCKET_H
#define CLIENTSOCKET_H

#include <QtNetwork>

#include "Packets/packet.h"
#include "Packets/playerjoinpacket.h"
#include "Packets/playerlistpacket.h"
#include "Packets/gamesettingspacket.h"
#include "Packets/roundstartpacket.h"
#include "Packets/sendanswerspacket.h"
#include "Packets/sendpointspacket.h"
#include "Packets/endgamepacket.h"
#include "Packets/playerfinishedpacket.h"
#include "Packets/endroundpacket.h"
#include "Packets/startcountdownpacket.h"

/**
 * @brief ClientSocker for communicating with the Server. Handle sending and receiving packets
 */
class ClientSocket : public QObject {
    Q_OBJECT

    public:
        ClientSocket();

        /**
         * @brief Connect to given host
         *
         * @param host      Hostname or IP
         * @param port      Port for connection
         * @param timeout   Time in milliseconds when timeout signal should emmited when no connection occured
         */
        void connectTo(QString host, quint16 port, int timeout=5000);

        /**
         * @brief Send packet to server
         *
         * @param packet    Reference to packet which should be sent
         */
        void send(Packet& packet);

    signals:

        /**
         * @brief Connected singal emitted on succesfull connection
         */
        void connected();

        /**
         * @brief Error signal emitted when any error occured
         */
        void error();

        /**
         * @brief Timeout signal emitted after timeout specified at connectTo()
         */
        void timeout();


        /**
         * @brief Emitted when a player joins the server
         *
         * @param packet    Packet with player name
         */
        void playerJoined(PlayerJoinPacket packet);

        /**
         * @brief Emitted when new player list is received from server
         *
         * @param packet    Packet with list of connected players
         */
        void receivedPlayerList(PlayerListPacket packet);

        /**
         * @brief Emitted when game settings are received. Used for identifying start of game
         *
         * @param packet    Packet with game settings
         */
        void receivedGameSettings(GameSettingsPacket packet);

        /**
         * @brief Emitted when when round start from sever is received
         *
         * @param packet    Packet with letter for current round
         */
        void roundStart(RoundStartPacket packet);

        /**
         * @brief Emitted when points are received from server
         *
         * @param packet    Packet with earned points for each category
         */
        void pointsSent(SendPointsPacket packet);

        /**
         * @brief Emitted when server signals end of game
         *
         * @param packet    Packet with leaderboard and scored points
         */
        void endGame(EndGamePacket packet);


        /**
         * @brief Emitted when a player finished his answers
         *
         * @param packet    Packet with playername
         */
        void playerFinished(PlayerFinishedPacket packet);


        /**
         * @brief Emitted when countdown for next round is starting
         *
         * @param packet    Empty packet
         */
        void startCountdown(StartCountdownPacket packet);


        /**
         * @brief Emitted when round ends
         *
         * @param packet    Empty packet
         */
        void endRound(EndRoundPacket packet);

    public slots:

        /**
         * @brief Reads data
         */
        void read();

        /**
         * @brief Handle timeout internally and emit timeout() signal
         */
        void handleTimeout();

        /**
         * @brief Handle connection internally and emit connect() signal
         */
        void handleConnection();

        /**
         * @brief Handle error internally and emit error() signal
         */
        void handleError();

    private:

        /**
         * @brief Identifiers for different states of connection
         */
        enum STATUS {
            CONNECTING,
            ERROR,
            CONNECTED
        };

        STATUS m_status;        /**< Current state of connection */
        QTcpSocket m_socket;    /**< Socket for connection */
};

#endif // CLIENTSOCKET_H

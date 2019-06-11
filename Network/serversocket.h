#ifndef SERVERSOCKET_H
#define SERVERSOCKET_H

#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>
#include <QVector>

#include "Packets/packet.h"
#include "Packets/playerjoinpacket.h"
#include "Packets/sendanswerspacket.h"
#include "Packets/sendpointspacket.h"
#include "Packets/endgamepacket.h"
#include "Packets/playerfinishedpacket.h"
#include "Packets/endroundpacket.h"
#include "Packets/startcountdownpacket.h"

/**
 * @brief Server for handling connections and sending/receiving packets
 */
class ServerSocket : public QObject {
    Q_OBJECT

    public:
        ServerSocket();

        /**
         * @brief Listen to specific port for connections
         *
         * @param port  Port to listen
         * @return
         */
        bool listen(quint16 port);

        /**
         * @brief Sends a packet to a client
         *
         * @param id        Id referencing the client
         * @param packet    Refrence to network packet to send
         * @return true if success, false if something went wrong
         */
        bool send(unsigned int id, Packet& packet);

    signals:
        /**
         * @brief Emits when new connection was accepted
         *
         * @param id    Identifier for connection
         */
        void connected(unsigned int id);

        /**
         * @brief Emits when client send a PlayerJoinPacket with player name
         *
         * @param packet    Packet with player name
         * @param id        Identifier for connection
         */
        void playerJoined(PlayerJoinPacket packet, unsigned int id);


        /**
         * @brief Emits when client sent the answers
         *
         * @param packet    Packet with Answers
         * @param id        Identifier for connection
         */
        void answersSent(SendAnswersPacket packet, unsigned int id);

        /**
         * @brief Emits when client set all answers and finished
         *
         * @param packet    Packet with player name
         * @param id        Identifier for connection
         */
        void playerFinished(PlayerFinishedPacket packet, unsigned int id);

    private slots:

        /**
         * @brief Slot gets called when socket is ready for read data
         */
        void read();

        /**
         * @brief Slot gets called on new connections
         */
        void newConnection();

    private:

        QTcpServer m_server;                        /**< QT server instance */
        QMap<unsigned int, QTcpSocket*> m_sockets;  /**< Sockets assigned to IDs */

        static unsigned int idCounter;              /**< Incrementing number used for give identifiers to connections */
};

#endif // SERVERSOCKET_H

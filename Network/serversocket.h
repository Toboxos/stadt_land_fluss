#ifndef SERVERSOCKET_H
#define SERVERSOCKET_H

#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>
#include <QVector>

#include "Network/Packets/packet.h"
#include "Network/Packets/playerjoinpacket.h"

/**
 * @brief Server for handling connections and sending/receiving packets
 */
class ServerSocket : public QObject {
    Q_OBJECT

    public:
        ServerSocket();

        /**
         * @brief Constructor with automatic listen
         *
         * @param port  Port which server listens to
         */
        ServerSocket(quint16 port);

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
        void playerJoined(PlayerJoinPacket packet, unsigned int id);

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

        static unsigned int idCounter;
};

#endif // SERVERSOCKET_H

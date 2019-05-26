#ifndef SERVERSOCKET_H
#define SERVERSOCKET_H

#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>
#include <vector>

#include "Network/Packets/packet.h"

/**
 * @brief Server for handling connections and sending/receiving packets
 */
class ServerSocket : QObject {
    Q_OBJECT

    public:
        /**
         * @brief Constructor starting server
         *
         * @param port  Port which server listen to
         */
        ServerSocket(quint16 port);

        /**
         * @brief Sends a packet to given player
         *
         * @param player    Player name where packet should send to
         * @param packet    Refrence to network packet to send
         * @return true if success, false if something went wrong
         */
        bool send(QString player, Packet& packet);

    public slots:

        /**
         * @brief Slot gets called when socket is ready for read data
         */
        void read();

        /**
         * @brief Slot gets called on new connections
         */
        void newConnection();

    private:

        QTcpServer m_server;                    /**< QT server instance */
        QVector<QTcpSocket*> m_sockets;         /**< Socket connections for all clients */
        QMap<QString, QTcpSocket*> m_mapped;    /**< Mapped players to socket */
};

#endif // SERVERSOCKET_H

#ifndef CLIENTSOCKET_H
#define CLIENTSOCKET_H

#include <QtNetwork>

#include <Network/Packets/packet.h>
#include <Network/Packets/playerjoinpacket.h>
#include <Network/Packets/playerlistpacket.h>

class ClientSocket : public QObject {
    Q_OBJECT

    public:
        ClientSocket();

        /**
         * @brief Connect to given host in constructor
         *
         * @param host  Hostname or IP
         * @param port  Port for connection
         */
        ClientSocket(QString host, quint16 port);

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
         * @param packet    Packet with information
         */
        void playerJoined(PlayerJoinPacket packet);

        /**
         * @brief Emitted when new player list is received from server
         *
         * @param packet    Packet with information
         */
        void receivedPlayerList(PlayerListPacket packet);

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
        enum STATUS {
            CONNECTING,
            ERROR,
            CONNECTED
        };

        STATUS m_status;
        QTcpSocket m_socket;
};

#endif // CLIENTSOCKET_H

#ifndef CLIENTSOCKET_H
#define CLIENTSOCKET_H

#include <QtNetwork>

#include <Network/Packets/packet.h>

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
         */
        void connectTo(QString host, quint16 port);

        /**
         * @brief Send packet to server
         *
         * @param packet    Reference to packet which should be sent
         */
        void send(Packet& packet);

    signals:
        void connected();

    public slots:
        void read();


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

#ifndef ROUNDSTARTPACKETTEST_H
#define ROUNDSTARTPACKETTEST_H

#include "../Network/serversocket.h"
#include "../Network/clientsocket.h"
#include "../Network/Packets/roundstartpacket.h"

class RoundStartPacketTest : public QObject {
    Q_OBJECT

    public:
        RoundStartPacketTest();
        void run();

    private slots:
        void server_connected(unsigned int id);

        void client_connected();
        void client_timeout();
        void client_error();

        void client_roundStart(RoundStartPacket packet);

    private:
        ServerSocket m_server;
        ClientSocket m_client;
};

#endif // ROUNDSTARTPACKETTEST_H

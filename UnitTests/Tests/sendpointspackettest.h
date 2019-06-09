#ifndef SENDPOINTSPACKETTEST_H
#define SENDPOINTSPACKETTEST_H

#include "test.h"
#include "Network/serversocket.h"
#include "Network/clientsocket.h"
#include "Network/Packets/sendpointspacket.h"

class SendPointsPacketTest : public Test {
    Q_OBJECT

    public:
        SendPointsPacketTest();
        void run();

    private slots:
        void server_connected(unsigned int id);

        void client_timeout();
        void client_error();

        void client_points(SendPointsPacket packet);

    private:
        ServerSocket m_server;
        ClientSocket m_client;
};

#endif // SENDPOINTSPACKETTEST_H

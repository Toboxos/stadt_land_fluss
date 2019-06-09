#ifndef PLAYERFINISHEDPACKETTEST_H
#define PLAYERFINISHEDPACKETTEST_H

#include "test.h"
#include "Network/serversocket.h"
#include "Network/clientsocket.h"
#include "Network/Packets/playerfinishedpacket.h"

class PlayerFinishedPacketTest : public Test {
    Q_OBJECT

    public:
        PlayerFinishedPacketTest();
        void run();

    private slots:
        void server_connected(unsigned int id);

        void client_timeout();
        void client_error();

        void client_playerFinished(PlayerFinishedPacket packet);

    private:
        ServerSocket m_server;
        ClientSocket m_client;
};

#endif // PLAYERFINISHEDPACKETTEST_H

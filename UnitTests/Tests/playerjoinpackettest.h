#ifndef PLAYERJOINPACKETTEST_H
#define PLAYERJOINPACKETTEST_H

#include "test.h"
#include "Network/serversocket.h"
#include "Network/clientsocket.h"
#include "Network/Packets/playerjoinpacket.h"

class PlayerJoinPacketTest : public Test {
    Q_OBJECT

    public:
        PlayerJoinPacketTest();
        void run();

    private slots:
        void server_connected(unsigned int id);

        void client_timeout();
        void client_error();

        void client_playerJoin(PlayerJoinPacket packet);

    private:
        ServerSocket m_server;
        ClientSocket m_client;
};

#endif // PLAYERJOINPACKETTEST_H

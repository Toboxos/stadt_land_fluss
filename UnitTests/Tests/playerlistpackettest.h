#ifndef PLAYERLISTPACKETTEST_H
#define PLAYERLISTPACKETTEST_H

#include "test.h"
#include "Network/serversocket.h"
#include "Network/clientsocket.h"
#include "Network/Packets/playerlistpacket.h"

class PlayerListPacketTest : public Test {
    Q_OBJECT

    public:
        PlayerListPacketTest();
        void run();

    private slots:
        void server_connected(unsigned int id);

        void client_timeout();
        void client_error();

        void client_playerList(PlayerListPacket packet);

    private:
        ServerSocket m_server;
        ClientSocket m_client;
};
#endif // PLAYERLISTPACKETTEST_H

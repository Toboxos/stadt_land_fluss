#ifndef ENDGAMEPACKETTEST_H
#define ENDGAMEPACKETTEST_H

#include "test.h"
#include "Network/serversocket.h"
#include "Network/clientsocket.h"
#include "Network/Packets/playerlistpacket.h"

class EndGamePacketTest : public Test {
    Q_OBJECT

    public:
        EndGamePacketTest();
        void run();

    private slots:
        void server_connected(unsigned int id);

        void client_timeout();
        void client_error();

        void client_endGame(EndGamePacket packet);

    private:
        ServerSocket m_server;
        ClientSocket m_client;
};

#endif // ENDGAMEPACKETTEST_H

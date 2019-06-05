#ifndef GAMESETTINGSPACKETTEST_H
#define GAMESETTINGSPACKETTEST_H

#include <QtTest/QTest>

#include "UnitTests/Tests/test.h"
#include "Network/serversocket.h"
#include "Network/clientsocket.h"
#include "Network/Packets/gamesettingspacket.h"

class GameSettingsPacketTest : public Test {
    Q_OBJECT

    public:
        GameSettingsPacketTest();
        void run();

    private slots:
        void server_connected(unsigned int id);

        void client_connected();
        void client_timeout();
        void client_error();

        void client_receivedGameSettings(GameSettingsPacket packet);

    private:
        ServerSocket m_server;
        ClientSocket m_client;
};

#endif // GAMESETTINGSPACKETTEST_H

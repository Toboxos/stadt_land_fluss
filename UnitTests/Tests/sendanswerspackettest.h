#ifndef SENDANSWERSPACKETTEST_H
#define SENDANSWERSPACKETTEST_H

#include "test.h"
#include "Network/serversocket.h"
#include "Network/clientsocket.h"
#include "Network/Packets/sendanswerspacket.h"

class SendAnswersPacketTest : public Test {
    Q_OBJECT

    public:
        SendAnswersPacketTest();
        void run();

    private slots:
        void client_connected();
        void client_timeout();
        void client_error();

        void server_answers(SendAnswersPacket packet, unsigned int id);

    private:
        ServerSocket m_server;
        ClientSocket m_client;
};

#endif // SENDANSWERSPACKETTEST_H

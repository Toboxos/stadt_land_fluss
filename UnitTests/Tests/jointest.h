#ifndef JOINTEST_H
#define JOINTEST_H

#include <QtTest/QTest>

#include "test.h"
#include "CLogik.h"

class JoinTest {

    public:
        JoinTest();
        void run(CLogik* logic);

        static void send(void* object, unsigned int id, Packet& packet);

    private:
        const static int m_playerCount = 5;

        unsigned int m_testStep;
        bool m_receivedPackets[m_playerCount];
};

#endif // JOINTEST_H

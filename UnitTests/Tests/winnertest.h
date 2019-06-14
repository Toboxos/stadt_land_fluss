#ifndef WINNERTEST_H
#define WINNERTEST_H

#include <QtTest/QTest>

#include "ServerLogic.h"

/**
 * @brief Tests the determination of the leaderboard from ServerLogic
 */
class WinnerTest {
    public:
        WinnerTest();
        void run(ServerLogic* logic);
};

#endif // WINNERTEST_H

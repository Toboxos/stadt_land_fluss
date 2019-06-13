#ifndef AWARDPOINTSTEST_H
#define AWARDPOINTSTEST_H

#include <QtTest/QTest>
#include <random>

#define private public
#define protected public
#include "ServerLogic.h"
#undef protected
#undef private

/**
 * @brief Tests the awarding of points from ServerLogic
 */
class AwardPointsTest {
    public:
        AwardPointsTest();
        void run(ServerLogic* logic);
};

#endif // AWARDPOINTSTEST_H

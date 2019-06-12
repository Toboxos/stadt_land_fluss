#ifndef AWARDPOINTSTEST_H
#define AWARDPOINTSTEST_H

#include <QtTest/QTest>
#include <random>

#define private public
#define protected public
#include "ServerLogic.h"
#undef protected
#undef private

class AwardPointsTest {
    public:
        AwardPointsTest();
        void run(ServerLogic* logic);
};

#endif // AWARDPOINTSTEST_H

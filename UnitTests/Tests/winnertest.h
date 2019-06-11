#ifndef WINNERTEST_H
#define WINNERTEST_H

#include <QtTest/QTest>

#define private public
#define protected public
#include "CLogik.h"
#undef private
#undef protected

class WinnerTest {
    public:
        WinnerTest();
        void run(CLogik* logic);
};

#endif // WINNERTEST_H

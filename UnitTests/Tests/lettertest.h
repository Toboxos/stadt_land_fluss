#ifndef LETTERTEST_H
#define LETTERTEST_H

#include <QtTest/QTest>
#include "ServerLogic.h"

class LetterTest {
    public:
        LetterTest();
        void run(ServerLogic* logic);
};

#endif // LETTERTEST_H

#ifndef LETTERTEST_H
#define LETTERTEST_H

#include <QtTest/QTest>
#include "ServerLogic.h"

/**
 * @brief Tests the generation of individual letters from the ServerLogic
 */
class LetterTest {
    public:
        LetterTest();
        void run(ServerLogic* logic);
};

#endif // LETTERTEST_H

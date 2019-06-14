#ifndef SERVERLOGICTESTS_H
#define SERVERLOGICTESTS_H

#include <QtTest/QTest>
#include "mock_classes/mockserversocket.h"

#define private public
#define protected public
#include "serverlogic.h"
#undef protected
#undef private

/**
 * @brief Unittest for testing different parts of server logic
 */
class ServerLogicTests : public QObject {
    Q_OBJECT

    private slots:
        // init() and cleanup() called before each test
        // creates and destroys new instance of serverlogic for each test
        void init();
        void cleanup();

        void testJoins();
        void testLetters();
        void testAwardPoints();
        void testWinner();

    private:
        /**
         * @brief Setup default game settings for testing server logic
         */
        void setupDefaultParameters();

        MockServerSocket m_serverSocket;    /**< Mock serversocket for intercepting packets */
        ServerLogic* m_logic;                    /**< Instance of server logic for tests */
};

#endif // SERVERLOGICTESTS_H

#include <QtTest/QtTest>
#include <QMetaObject>
#include "mock_classes/mockserversocket.h"

#define private public
#define protected public
#include "CLogik.h"
#undef protected
#undef private

#include "Tests/jointest.h"
#include "Tests/lettertest.h"
#include "Tests/awardpointstest.h"
#include "Tests/winnertest.h"


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
        CLogik* m_logic;                    /**< Instance of server logic for tests */
};

void ServerLogicTests::init() {
    m_logic = new CLogik();
}

void ServerLogicTests::cleanup() {
    delete m_logic;
}

void ServerLogicTests::setupDefaultParameters() {
    m_logic->getSpieleinstellungen()->setRoundNumber(7);
    m_logic->getSpieleinstellungen()->setRoundTimeLimit(2);
    m_logic->getSpieleinstellungen()->setCountdown(10);
    m_logic->getSpieleinstellungen()->setPlayName("Test");
    m_logic->getSpieleinstellungen()->addKategorie("Stadt");
    m_logic->getSpieleinstellungen()->addKategorie("Land");
    m_logic->getSpieleinstellungen()->addKategorie("Fluss");
    m_logic->getSpieleinstellungen()->addKategorie("Punkte");
}

void ServerLogicTests::testJoins() {
    setupDefaultParameters();


    JoinTest test;
    m_serverSocket.setCallbackSend(&JoinTest::send, &test);
    m_logic->serverSocket = m_serverSocket;
    test.run(m_logic);
}

void ServerLogicTests::testLetters() {
    LetterTest test;
    test.run(m_logic);
}

void ServerLogicTests::testAwardPoints() {
    setupDefaultParameters();

    AwardPointsTest test;
    test.run(m_logic);
}

void ServerLogicTests::testWinner() {
   setupDefaultParameters();

   WinnerTest test;
   test.run(m_logic);
}

QTEST_MAIN(ServerLogicTests);
#include "serverlogictests.moc"

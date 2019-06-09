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

class ServerLogicTest : public QObject {
    Q_OBJECT

    private slots:
        void init();
        void cleanup();

        void testJoins();
        void testLetters();
        void testAwardPoints();

    private:
        void setupDefaultParameters();

        MockServerSocket m_serverSocket;
        CLogik* m_logic;
};

void ServerLogicTest::init() {
    m_logic = new CLogik();
}

void ServerLogicTest::cleanup() {
    delete m_logic;
}

void ServerLogicTest::setupDefaultParameters() {
    m_logic->getSpieleinstellungen()->setRoundNumber(7);
    m_logic->getSpieleinstellungen()->setRoundTimeLimit(2);
    m_logic->getSpieleinstellungen()->setCountdown(10);
    m_logic->getSpieleinstellungen()->setPlayName("Test");
    m_logic->getSpieleinstellungen()->addKategorie("Stadt");
    m_logic->getSpieleinstellungen()->addKategorie("Land");
    m_logic->getSpieleinstellungen()->addKategorie("Fluss");
    m_logic->getSpieleinstellungen()->addKategorie("Punkte");
}

void ServerLogicTest::testJoins() {
    setupDefaultParameters();


    JoinTest test;
    m_serverSocket.setCallbackSend(&JoinTest::send, &test);
    m_logic->serverSocket = m_serverSocket;
    test.run(m_logic);
}

void ServerLogicTest::testLetters() {
    LetterTest test;
    test.run(m_logic);
}

void ServerLogicTest::testAwardPoints() {
    setupDefaultParameters();

    AwardPointsTest test;
    test.run(m_logic);
}

QTEST_MAIN(ServerLogicTest);
#include "serverlogictest.moc"

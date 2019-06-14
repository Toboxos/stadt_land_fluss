#include "serverlogictests.h"

#include "Tests/jointest.h"
#include "Tests/lettertest.h"
#include "Tests/awardpointstest.h"
#include "Tests/winnertest.h"


void ServerLogicTests::init() {
    m_logic = new ServerLogic();
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

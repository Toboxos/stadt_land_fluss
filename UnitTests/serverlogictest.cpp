#include <QtTest/QtTest>
#include <QMetaObject>
#include "mock_classes/mockserversocket.h"

#define private public
#include "CLogik.h"
#undef private

class ServerLogicTest : public QObject {
    Q_OBJECT

    private slots:
        void initTestCase();

        void init();
        void cleanup();

        void testJoins();

    private:
        static bool send(void* object, unsigned int id, Packet& packet);
        static bool listen(void* object, quint16 port);

        void setupDefaultParameters();

        MockServerSocket m_serverSocket;
        CLogik* m_logic;
};

void ServerLogicTest::initTestCase() {
    m_serverSocket.setCallbackSend(&ServerLogicTest::send, this);
    m_serverSocket.setCallbackListen(&ServerLogicTest::listen, this);
}

void ServerLogicTest::init() {
    m_logic = new CLogik();
    m_logic->serverSocket = m_serverSocket;
}

void ServerLogicTest::cleanup() {
    delete m_logic;
}

bool ServerLogicTest::send(void* object, unsigned int id, Packet& packet) {
    qDebug() << "Send " << PACKET_TYPE_NAMES[packet.getType()] << " to " << id;
    return true;
}

bool ServerLogicTest::listen(void* object, quint16 port) {
    return true;
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

    m_logic->starteServerSocket();
    for( int i = 0; i < 3; ++i ) {
        QString s = "Player " + QString::number(i);
        PlayerJoinPacket p(s);
        m_logic->spieler_beitritt(p, i);
    }
    m_logic->sendeSpielStart();
}

QTEST_MAIN(ServerLogicTest);
#include "serverlogictest.moc"

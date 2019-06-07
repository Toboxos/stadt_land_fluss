#include <QtTest/QtTest>
#include "mock_classes/mockserversocket.h"

/*#define private public
#include "CLogik.h"
#undef private
*/
class ServerLogicTest : public QObject {
    Q_OBJECT

    public:

    private slots:
        void initTestCase();

        void init();
        void cleanup();

        void testJoins();

    private:
        static bool send(void* object, unsigned int id, Packet& packet);
        static bool listen(void* object, quint16 port);

        MockServerSocket m_serverSocket;
        //CLogik* m_logic;
};

void ServerLogicTest::initTestCase() {
    m_serverSocket.setCallbackSend(&ServerLogicTest::send, this);
    m_serverSocket.setCallbackListen(&ServerLogicTest::listen, this);
}

void ServerLogicTest::init() {
  //  m_logic = new CLogik();
}

void ServerLogicTest::cleanup() {
    //delete m_logic;
}

bool ServerLogicTest::send(void* object, unsigned int id, Packet& packet) {
    return true;
}

bool ServerLogicTest::listen(void* object, quint16 port) {
    return true;
}

void ServerLogicTest::testJoins() {

}

QTEST_MAIN(ServerLogicTest);
#include "serverlogictest.moc"

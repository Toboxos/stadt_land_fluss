#include "sendanswerspackettest.h"

SendAnswersPacketTest::SendAnswersPacketTest() {

}

void SendAnswersPacketTest::run() {
    connect(&m_server, SIGNAL(answersSent(SendAnswersPacket, unsigned int)), this, SLOT(server_answers(SendAnswersPacket, unsigned)));
    m_server.listen(PORT);

    connect(&m_client, SIGNAL(connected()), this, SLOT(client_connected()));
    connect(&m_client, SIGNAL(timeout()), this, SLOT(client_timeout()));
    connect(&m_client, SIGNAL(error()), this, SLOT(client_error()));
    m_client.connectTo("localhost", PORT);
}

void SendAnswersPacketTest::client_timeout() {
    emit failed("Client connection timeout");
}

void SendAnswersPacketTest::client_error() {
    emit failed("Client connection error");
}

void SendAnswersPacketTest::client_connected() {
    QVector<QString> vec;
    for( int i = 0; i < 5; ++i ) {
        QString s = "Answer " + QString::number(i);
        vec.push_back(s);
    }

    SendAnswersPacket packet(vec);
    m_client.send(packet);
}

void SendAnswersPacketTest::server_answers(SendAnswersPacket packet, unsigned int id) {
    QVector<QString> answers = packet.getAnswers();
    for( int i = 0; i < 5; ++i ) {
        QString s = "Answer " + QString::number(i);
        QCOMPARE(answers[i], s);
    }

    emit finished();
}

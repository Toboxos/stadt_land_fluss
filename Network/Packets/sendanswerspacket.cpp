#include "sendanswerspacket.h"

SendAnswersPacket::SendAnswersPacket()
{
    m_type = SEND_ANSWERS_PACKET;
}

SendAnswersPacket::SendAnswersPacket(QVector<QString> answers){
    m_type = SEND_ANSWERS_PACKET;
    m_answers = answers;
}

void SendAnswersPacket::setAnswers(QVector<QString> answers){
    m_answers = answers;
}

QVector<QString> SendAnswersPacket::getAnswers(){
    return m_answers;
}

void SendAnswersPacket::writeData(QTcpSocket& socket) {
    int size = m_answers.size();
    writeInteger(socket, size);

    for( int i = 0; i < size; ++i ) {
        writeQString(socket, m_answers[i]);
    }
}

void SendAnswersPacket::readData(QTcpSocket& socket) {
    int size = 0;
    readInteger(socket, size);

    m_answers.clear();
    for( int i = 0; i < size; ++i ) {
        QString answer;
        readQString(socket, answer);
        m_answers.push_back(answer);
    }
}

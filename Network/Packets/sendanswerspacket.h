#ifndef SENDANSWERSPACKET_H
#define SENDANSWERSPACKET_H

#include "packet.h"

class SendAnswersPacket : public Packet
{
public:
    SendAnswersPacket();
    SendAnswersPacket(QVector<QString> answers);

    void setAnswers(QVector<QString> answers);
    QVector<QString> getAnswers();

    void writeData(QTcpSocket& socket);
    void readData(QTcpSocket& socket);

private:
    QVector<QString> m_answers;
};

#endif // SENDANSWERSPACKET_H

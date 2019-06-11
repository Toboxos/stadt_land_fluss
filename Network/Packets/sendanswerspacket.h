#ifndef SENDANSWERSPACKET_H
#define SENDANSWERSPACKET_H

#include "packet.h"

/**
 * @brief Packet for sending the answers from client to server */
 */
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
    QVector<QString> m_answers; /**< Answers of player in the order of the categories */
};

#endif // SENDANSWERSPACKET_H

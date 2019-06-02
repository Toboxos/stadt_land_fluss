#ifndef ENDGAMEPACKET_H
#define ENDGAMEPACKET_H

#include "packet.h"

class EndGamePacket : public Packet
{
public:
    EndGamePacket();
    EndGamePacket(QVector<QString> ranking);

    void setRanking(QVector<QString> ranking);
    QVector<QString> getRanking();

    void writeData(QTcpSocket& socket);
    void readData(QTcpSocket& socket);

private:
    QVector<QString> m_ranking;
};

#endif // ENDGAMEPACKET_H

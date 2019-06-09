#ifndef ENDGAMEPACKET_H
#define ENDGAMEPACKET_H

#include "packet.h"

class EndGamePacket : public Packet
{
public:
    EndGamePacket();
    EndGamePacket(QVector<QString> ranking, QVector<int> points);

    void setRanking(QVector<QString> ranking);
    void setPoints(QVector<int> points);
    QVector<QString> getRanking();
    QVector<int> getPoints();

    void writeData(QTcpSocket& socket);
    void readData(QTcpSocket& socket);

private:
    QVector<int> m_points;
    QVector<QString> m_ranking;
};

#endif // ENDGAMEPACKET_H

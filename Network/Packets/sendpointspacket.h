#ifndef SENDPOINTSPACKET_H
#define SENDPOINTSPACKET_H
#include "packet.h"

class SendPointsPacket : public Packet
{
public:
    SendPointsPacket();
    SendPointsPacket(QVector<int> v_points, int totalpoints);

    void setPoints(QVector<int> v_points);
    QVector<int> getPoints();

    void setTotalPoints(int totalpoints);
    int getTotalPoints();

    void writeData(QTcpSocket& socket);
    void readData(QTcpSocket& socket);

private:
    QVector<int> m_points;
    int m_totalpoints;
};

#endif // SENDPOINTSPACKET_H

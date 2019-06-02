#ifndef SENDPOINTSPACKET_H
#define SENDPOINTSPACKET_H
#include "packet.h"

class SendPointsPacket
{
public:
    SendPointsPacket();
    SendPointsPacket(QVector<int> v_points, int totalpoints);

    void setPoints(QVector<int> v_points);
    QVector<int> getPoints();

    void setTotalPoints(int totalpoints);
    int getTotalPoints();


};

#endif // SENDPOINTSPACKET_H

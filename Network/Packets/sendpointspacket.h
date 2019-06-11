#ifndef SENDPOINTSPACKET_H
#define SENDPOINTSPACKET_H
#include "packet.h"

/**
 * @brief Packet for telling client scored points of round
 */
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
    QVector<int> m_points;  /** Points in order of categories */
    int m_totalpoints;      /** Total of earned points of all rounds */
};

#endif // SENDPOINTSPACKET_H

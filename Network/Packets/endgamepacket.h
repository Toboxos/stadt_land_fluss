#ifndef ENDGAMEPACKET_H
#define ENDGAMEPACKET_H

#include "packet.h"

/**
 * @brief Holds leaderboard and signals end of game
 */
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
    QVector<int> m_points;      /**< Points in order of leaderboard */
    QVector<QString> m_ranking; /**< Player names in order of leaderboard */
};

#endif // ENDGAMEPACKET_H

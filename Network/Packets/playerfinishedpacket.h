#ifndef PLAYERFINISHEDPACKET_H
#define PLAYERFINISHEDPACKET_H
#include "packet.h"

/**
 * @brief Informing, that a player has sent his answers and is finished.
 */
class PlayerFinishedPacket : public Packet {
    public:
        PlayerFinishedPacket();
        PlayerFinishedPacket(QString name);

        void setName(QString name);
        QString getName();

        void readData(QTcpSocket& socket);
        void writeData(QTcpSocket& socket);

    private:
        QString m_name; /**< Name of player who has finished */
};

#endif // PLAYERFINISHEDPACKET_H

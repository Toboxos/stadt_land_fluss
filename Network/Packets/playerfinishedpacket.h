#ifndef PLAYERFINISHEDPACKET_H
#define PLAYERFINISHEDPACKET_H
#include "packet.h"

class PlayerFinishedPacket
{
public:
    PlayerFinishedPacket();

    void readData(QTcpSocket& socket);
    void writeData(QTcpSocket& socket);

};

#endif // PLAYERFINISHEDPACKET_H

#ifndef STARTCOUNTDOWNPACKET_H
#define STARTCOUNTDOWNPACKET_H
#include "packet.h"

class StartCountdownPacket : public Packet
{
public:
    StartCountdownPacket();
    void writeData(QTcpSocket& socket);
    void readData(QTcpSocket& socket);
};

#endif // STARTCOUNTDOWNPACKET_H

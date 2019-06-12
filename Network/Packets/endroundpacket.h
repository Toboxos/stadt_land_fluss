#ifndef ENDROUNDPACKET_H
#define ENDROUNDPACKET_H
#include "packet.h"

/**
 * @brief Packet used for signal end of round
 */
class EndRoundPacket : public Packet
{
public:
    EndRoundPacket();
    void writeData(QTcpSocket& socket);
    void readData(QTcpSocket& socket);
};

#endif // ENDROUNDPACKET_H

#ifndef ROUNDSTARTPACKET_H
#define ROUNDSTARTPACKET_H

#include "packet.h"

class RoundStartPacket : public Packet {
        public:
            RoundStartPacket();
            RoundStartPacket(const char letter);

            void setLetter(const char letter);
            char getLetter();

            void writeData(QTcpSocket& socket);
            void readData(QTcpSocket& socket);
        private:
            char m_letter;
};

#endif // ROUNDSTARTPACKET_H

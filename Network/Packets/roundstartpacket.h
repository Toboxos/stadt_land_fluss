#ifndef ROUNDSTARTPACKET_H
#define ROUNDSTARTPACKET_H

#include "packet.h"

/**
 * @brief Packet signals start of round with letter for the round
 */
class RoundStartPacket : public Packet {
        public:
            RoundStartPacket();
            RoundStartPacket(const char letter);

            void setLetter(const char letter);
            char getLetter();

            void writeData(QTcpSocket& socket);
            void readData(QTcpSocket& socket);
        private:
            char m_letter;  /**< Letter used for round */
};

#endif // ROUNDSTARTPACKET_H

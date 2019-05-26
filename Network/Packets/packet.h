#ifndef PACKET_H
#define PACKET_H

#include <QtNetwork/QTcpSocket>

/**
 * @brief Enum for diffrent types of packets
 */
enum PACKET_TYPE {
    BASE_PACKET,
    PLAYER_JOIN_PACKET
};

/**
 * @brief Base class for Packets
 *
 * @details All packets are derived from this class.
 *          This class implements all what is needed for sending and receiving any packet
 *
 * @author Tobias Bungard
 */
class Packet {
    public:
        Packet();
        virtual ~Packet();

        /**
         * @return Id of packettype
         */
        PACKET_TYPE getType();

        /**
         * @brief Read data from socket and fill the packet members
         *
         * @param socket    Pointer to socket data should be read from
         */
        virtual void readData(QTcpSocket* socket) = 0;

        /**
         * @brief Write data from members to socket
         *
         * @param socket    Pointer to socket data should be written to
         */
        virtual void writeData(QTcpSocket* socket) = 0;

    protected:
        PACKET_TYPE m_type; /**< Id of packettype */
};

#endif // PACKET_H

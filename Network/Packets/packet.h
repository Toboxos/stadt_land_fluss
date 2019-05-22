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
         * @brief Unpack packet and write all data on QTcpSocket
         *
         * @param socket    QTcpSocket data should be written to
         * @return Same QTcpSocket as given
         */
        virtual QTcpSocket& operator<<(QTcpSocket& socket);

        /**
         * @brief Read data from socket and fill the packet
         *
         * @param socket    QTcpSocket data should read from
         * @return Same QTcpSocket as given
         */
        virtual QTcpSocket& operator>>(QTcpSocket& socket);

        /**
         * @return Id of packettype
         */
        int getType();

    protected:
        int m_type; /**< Id of packettype */
};

#endif // PACKET_H

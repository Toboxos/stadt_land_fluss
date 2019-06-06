#ifndef PACKET_H
#define PACKET_H

#include <QtNetwork/QTcpSocket>

/**
 * @brief Enum for diffrent types of packets
 */
enum PACKET_TYPE {
    BASE_PACKET,
    PLAYER_JOIN_PACKET,
    PLAYER_LIST_PACKET,
    GAME_SETTINGS_PACKET,
    ROUND_START_PACKET,
    SEND_ANSWERS_PACKET,
    SEND_POINTS_PACKET,
    END_GAME_PACKET,
    PLAYER_FINISHED_PACKET,
    START_COUNTDOWN_PACKET,
    END_ROUND_PACKET
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
         * @param socket    Socket data should be read from
         */
        virtual void readData(QTcpSocket& socket) = 0;

        /**
         * @brief Write data from members to socket
         *
         * @param socket    Socket data should be written to
         */
        virtual void writeData(QTcpSocket& socket) = 0;

    protected:
        PACKET_TYPE m_type; /**< Id of packettype */

        /**
         * @brief Writes a QString to the socket
         *
         * @param socket    Socket data should written to
         * @param QString    QString reference which should be written
         */
        static void writeQString(QTcpSocket& socket, QString& QString);

        /**
         * @brief Reads a QString from the socket
         *
         * @param socket    Socket data should read from
         * @param QString    QString reference which should be updated
         */
        static void readQString(QTcpSocket& socket, QString& QString);

        /**
         * @brief Writes an Integer to the socket
         *
         * @param socket    Socket data should written to
         * @param integer   Integer reference which should be written
         */
        static void writeInteger(QTcpSocket& socket, int& integer);

        /**
         * @brief Read an Integer from the socket
         *
         * @param socket    Socket data should read from
         * @param integer   Integer reference which should be updated
         */
        static void readInteger(QTcpSocket& socket, int& integer);
};

#endif // PACKET_H

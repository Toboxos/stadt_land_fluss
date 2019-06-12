#ifndef PLAYERLISTPACKET_H
#define PLAYERLISTPACKET_H

#include "packet.h"

/**
 * @brief Packet for sending list of all connected players
 */
class PlayerListPacket : public Packet {

    public:
        PlayerListPacket();

        /**
         * @brief Constructor to auto set data
         *
         * @param players   Vector of players
         */
        PlayerListPacket(QVector<QString> players);

        void setPlayers(QVector<QString> players);
        QVector<QString> getPlayers();

        void readData(QTcpSocket& socket);
        void writeData(QTcpSocket& socket);

    private:
        QVector<QString> m_players; /**< List of connected players */
};

#endif // PLAYERLISTPACKET_H

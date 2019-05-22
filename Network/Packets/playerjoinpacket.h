#ifndef PLAYERJOINPACKET_H
#define PLAYERJOINPACKET_H

#include "packet.h"

/**
 * @brief This packet will be send when a player joins the game
 */
class PlayerJoinPacket : Packet {

    public:
        /**
         * @param name  Name of player
         */
        PlayerJoinPacket(QString name);

        QTcpSocket& PlayerJoinPacket::operator<<(QTcpSocket& socket);
        QTcpSocket& PlayerJoinPacket::operator>>(QTcpSocket& socket);

    private:
        QString m_name; /**< Name of player */
};

#endif // PLAYERJOINPACKET_H

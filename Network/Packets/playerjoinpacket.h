#ifndef PLAYERJOINPACKET_H
#define PLAYERJOINPACKET_H

#include "packet.h"

/**
 * @brief This packet will be send when a player joins the game
 */
class PlayerJoinPacket : public Packet {

    public:
        PlayerJoinPacket();

        /**
         * @param name  Name of player
         */
        PlayerJoinPacket(QString name);

        void setName(QString name);
        QString getName();


        void readData(QTcpSocket* socket);
        void writeData(QTcpSocket* socket);

    private:
        QString m_name; /**< Name of player */
};

#endif // PLAYERJOINPACKET_H

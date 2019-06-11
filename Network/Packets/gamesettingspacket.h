#ifndef GAMESETTINGSPACKET_H
#define GAMESETTINGSPACKET_H

#include "packet.h"

/**
 * @brief Packet holds game settings from server
 */
class GameSettingsPacket : public Packet {
    public:
        GameSettingsPacket();
        GameSettingsPacket(
                QString gameName,
                int roundNumbers,
                int roundDuration,
                int countdown,
                QVector<QString> categories
        );

        void setGameName(QString gameName);
        void setRoundNumbers(int roundNumbers);
        void setRoundDuration(int roundDuration);
        void setCountdown(int countdown);
        void setCategories(QVector<QString> categories);

        QString getGameName();
        int getRoundNumbers();
        int getRoundDuration();
        int getCountown();
        QVector<QString> getCategories();

        void readData(QTcpSocket& socket);
        void writeData(QTcpSocket& socket);

    private:
        QString m_gameName;             /**< Name of the game */
        int m_roundNumbers;             /**< Number of round which get played */
        int m_roundDuration;            /**< Duration of one round */
        int m_countdown;                /**< Countdown after player finished */
        QVector<QString> m_categories;  /**< Names of Categories */

};

#endif // GAMESETTINGSPACKET_H

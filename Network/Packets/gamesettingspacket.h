#ifndef GAMESETTINGSPACKET_H
#define GAMESETTINGSPACKET_H

#include "packet.h"

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
        QString m_gameName;
        int m_roundNumbers;
        int m_roundDuration;
        int m_countdown;
        QVector<QString> m_categories;

};

#endif // GAMESETTINGSPACKET_H

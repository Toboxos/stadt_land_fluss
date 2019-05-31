#include "gamesettingspacket.h"

GameSettingsPacket::GameSettingsPacket() {
    m_type = GAME_SETTINGS_PACKET;
}

GameSettingsPacket::GameSettingsPacket(QString gameName, int roundNumbers, int roundDuration, int countdown, QVector<QString> categories) {
    m_type = GAME_SETTINGS_PACKET;
    m_gameName = gameName;
    m_roundNumbers = roundNumbers;
    m_roundDuration = roundDuration;
    m_countdown  = countdown;
    m_categories = categories;
}

void GameSettingsPacket::setGameName(QString gameName) {
    m_gameName = gameName;
}

void GameSettingsPacket::setRoundNumbers(int roundNumbers) {
    m_roundNumbers = roundNumbers;
}

void GameSettingsPacket::setRoundDuration(int roundDuration) {
    m_roundDuration = roundDuration;
}

void GameSettingsPacket::setCountdown(int countdown) {
    m_countdown = countdown;
}

void GameSettingsPacket::setCategories(QVector<QString> categories) {
    m_categories = categories;
}

QString GameSettingsPacket::getGameName() {
    return m_gameName;
}

int GameSettingsPacket::getRoundNumbers() {
    return m_roundNumbers;
}

int GameSettingsPacket::getRoundDuration() {
    return m_roundDuration;
}

int GameSettingsPacket::getCountown() {
    return m_countdown;
}

QVector<QString> GameSettingsPacket::getCategories() {
    return m_categories;
}

void GameSettingsPacket::writeData(QTcpSocket &socket) {
    writeQString(socket, m_gameName);
    writeInteger(socket, m_roundNumbers);
    writeInteger(socket, m_roundDuration);
    writeInteger(socket, m_countdown);

    int size = m_categories.size();
    writeInteger(socket, size);

    auto end = m_categories.end();
    for( auto it = m_categories.begin(); it != end; ++it ) {
        writeQString(socket, *it);
    }
}

void GameSettingsPacket::readData(QTcpSocket &socket) {
    readQString(socket, m_gameName);
    readInteger(socket, m_roundNumbers);
    readInteger(socket, m_roundDuration);
    readInteger(socket, m_countdown);

    int size = 0;
    readInteger(socket, size);

    m_categories.clear();
    for( int i = 0; i < size; ++i ) {
        QString s;
        readQString(socket, s);
        m_categories.push_back(s);
    }
}

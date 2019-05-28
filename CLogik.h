#pragma once
#include <stdint.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <QtCore/QObject>


#include "Network/serversocket.h"
#include "antworten.h"
#include "spieler.h"
#include "punkte.h"
#include "Network/serversocket.h"
#include "spieleinstellungen.h"

using namespace std;

class CLogik : public QObject {
    Q_OBJECT
public:
    CLogik();
    ~CLogik();

    int createPlayer(std::string);
    vector<std::string> sortAnswers(unsigned int);
    vector<int> awardPoints(unsigned int);
    void Punktevergabe();
    vector<std::string> getWinner();
    char getLetter();

public slots:
    void playerJoined(PlayerJoinPacket, unsigned int);
private:
    std::vector<Spieler> players;
    std::vector<antworten> answers;
    std::vector<punkte> points;
    char letters[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char usedLetters[26];
    ServerSocket _serverSocket;
    std::vector<Spieler> _spielerListe;



};

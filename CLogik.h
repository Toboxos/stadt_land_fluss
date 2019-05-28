#pragma once
#include <stdint.h>
#include <iostream>
#include <vector>
#include <stdlib.h>

#include "antworten.h"
#include "spieler.h"
#include "punkte.h"
#include "Network/clientsocket.h"
#include "spieleinstellungen.h"

using namespace std;

class CLogik {
public:
    CLogik();
    ~CLogik();

    int createPlayer(std::string);
    vector<std::string> sortAnswers(unsigned int);
    vector<int> awardPoints(unsigned int);
    void Punktevergabe();
    vector<std::string> getWinner();
    char getLetter();
	
private:
    std::vector<Spieler> players;
    std::vector<antworten> answers;
    std::vector<punkte> points;
    char letters[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char usedLetters[26];



};

#pragma once
#include <stdint.h>
#include <iostream>
#include <vector>

#include "antworten.h"
#include "spieler.h"
#include "punkte.h"

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
	
private:
    std::vector<Spieler> players;
    std::vector<antworten> answers;
    std::vector<punkte> points;
};

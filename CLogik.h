#pragma once
#include <stdint.h>
#include <iostream>
#include <vector>

#include "CSpieler.h"

using namespace std;

class CLogik {
public:
    CLogik();
    ~CLogik();

    void createPlayer(string n, int c);
	void awardPoints();
	string getWinner();
	
private:
	vector<CSpieler> players;
};
//Kommentar :)

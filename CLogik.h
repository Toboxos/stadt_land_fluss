#pragma once
#include <stdint.h>
#include <iostream>
#include <vector>
using namespace std;

class CLogik {
public:
	CLogik() {};
	~CLogik() {};

	void createPlayer();
	void awardPoints();
	string getWinner();
	
private:
	vector<CSpieler> players;
};
//Kommentar :)
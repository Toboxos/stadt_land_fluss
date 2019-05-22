#pragma once
#include <stdint.h>
#include <iostream>
#include <vector>
using namespace std;

class CSpieler {
public:
    CSpieler(string n, int c);
    //~CSpieler();

	int getPoints();
	void setPoints(int i);

	string getName();
	void setName(string n);

	string getAnswer(int i);
	void setAnswer(int i, string a);

	int getCredit(int i);
	void setCredit(int i,int j);

private:
	int points;
	string name;
	vector<string> answers;
	vector<int> credit;
};

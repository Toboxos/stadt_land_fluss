#include "punkte.h"

punkte::punkte(vector<int> p)
{
    points = p;
}

vector<int> punkte::getPunkte(){
    return points;
}

void punkte::setPunkte(int i, int p){
    points[i] = p;
}

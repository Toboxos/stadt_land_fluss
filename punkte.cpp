#include "punkte.h"

punkte::punkte() {

}

punkte::punkte(QVector<int> p)
{
    points = p;
}

punkte::~punkte() {

}

QVector<int> punkte::getPunkte(){
    return points;
}

void punkte::setPunkte(int i, int p){
    points[i] = p;
}

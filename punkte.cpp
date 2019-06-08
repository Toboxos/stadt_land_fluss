#include "punkte.h"

punkte::punkte() {

}

punkte::punkte(QVector<int> p)
{
    points = p;
}

QVector<int> punkte::getPunkte(){
    return points;
}

void punkte::setPunkte(int i, int p){
    points.replace(i,p);
}

int punkte::getEinenPunkt(int s){
    return points.at(s);
}

#include "spieler.h"


Spieler::Spieler(std::string name,int c)
{
   _name = name;
   static int _nextId;
   _id = _nextId;
   _nextId ++;
   answers.resize(c);
   credits.resize(c);
}

std::string Spieler::getName()
{
    return _name;
}

int Spieler::getId()
{
    return _id;
}

int Spieler::getPunkte()
{
    return _punkte;
}

void Spieler::setPunkte(int punkte)
{
    _punkte = punkte;
}

unsigned int Spieler::Categories(){
    unsigned int c = answers.size();
    return c;
}

std::string Spieler::getAnswer(unsigned int i){
    std::string p = answers.at(i);
    return p;
}

void Spieler::setAnswer(unsigned int i, std::string a){
    answers[i]=a;
}

int Spieler::getCredit(unsigned int i){
    int p = credits.at(i);
    return p;
}

void Spieler::setCredit(unsigned int i, int j){
    credits[i]=j;
}



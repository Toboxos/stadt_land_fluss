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

std::string Spieler::getAnswer(int i){
    //return Element der Liste an Stelle i
}

void Spieler::setAnswer(int i, std::string a){
    //schreibt Antwort a an Stelle i
}

int Spieler::getCredit(int i){
    //return Element der Liste an Stelle i
}

void Spieler::setCredit(int i, int j){
    //schreibt an Stelle i die Punktzahl j
}



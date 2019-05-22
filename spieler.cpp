#include "spieler.h"


Spieler::Spieler(std::string name)
{
   _name = name;
   static int _nextId;
   _id = _nextId;
   _nextId ++;
}
int Spieler::getId()
{
    return _id;
}
std::string Spieler::getName()
{
    return _name;
}

int Spieler::getPunkte()
{
    return _punkte;
}
void Spieler::setPunkte(int punkte)
{
    _punkte = punkte;
}




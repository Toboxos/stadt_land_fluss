#include "spieler.h"


Spieler::Spieler(std::string name)
{
   _name = name;
   static int _nextId;
   _id = _nextId;
   _nextId ++;
}

//gibt den Spielernamen zurück
std::string Spieler::getName()
{
    return _name;
}

//gibt die Spieler ID zurück
int Spieler::getId()
{
    return _id;
}

void Spieler::setConnectionId(unsigned int id){
    connectionId = id;
}

unsigned int Spieler::getConnectionId(){
    return connectionId;
}

//gibt die Gesamtpunktzahl des Spielers zurück
int Spieler::getPunkte()
{
    return _punkte;
}

//setzt die Gesamtpunktzahl des Spielers
void Spieler::setPunkte(int punkte)
{
    _punkte = punkte;
}

//gibt die Anzahl der Kategorien zurück
unsigned int Spieler::Categories(){
    unsigned int c = answers.size();
    return c;
}


//gibt die Antworten des Spielers in der Runde zurück
std::string Spieler::getAnswer(unsigned int i){
    std::string p = answers.at(i);
    return p;
}

//setzt die Antwort in der Runde für Kategorie Nr i
void Spieler::setAnswer(unsigned int i, std::string a){
    answers[i]=a;
}

//gibt die Punkte des Spielers in der Runde zurück
vector<int> Spieler::getCredit(){
    vector<int> p = credits;
    return p;
}

//setzt die Punkte der Runde für Kategorie Nr i
void Spieler::setCredit(unsigned int i, int j){
    credits[i]=j;
}



#include "spieleinstellungen.h"

Spieleinstellungen::Spieleinstellungen()
{

}
int Spieleinstellungen::getRundenanzahl(){return _rundenanzahl ;}
int Spieleinstellungen::getRundendauer(){return _rundendauer;}
int Spieleinstellungen::getCountdown(){return _countdown;}
std::string Spieleinstellungen::getSpielname(){return _spielname;}
std::vector<std::string> Spieleinstellungen::getKategorienListe(){return _kategorienListe;}
int Spieleinstellungen::getKategorieSize(){return _kategorienListe.size();}

void Spieleinstellungen::setPlayName(std::string spielname){_spielname=spielname;}
void Spieleinstellungen::setRoundNumber(int rundenanzahl){_rundenanzahl = rundenanzahl;}
void Spieleinstellungen::setRoundTimeLimit(int rundendauer){_rundendauer = rundendauer;}
void Spieleinstellungen::setCountdown(int countdown){_countdown=countdown;}

void Spieleinstellungen::setKategorienlListe(std::string newKategorie)
{
    _kategorienListe.push_back(newKategorie);
}

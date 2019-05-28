#ifndef SPIELEINSTELLUNGEN_H
#define SPIELEINSTELLUNGEN_H
#include <string>
#include <vector>
#include <kategorienserver.h>
class Spieleinstellungen
{
public:
    Spieleinstellungen();
    int getRundenanzahl();
    int getRundendauer();
    int getCountdown();
    std::string getSpielname();
    std::vector<std::string> getKategorienListe();
    int getKategorieSize();


    void setPlayName(std::string);
    void setRoundNumber(int);
    void setRoundTimeLimit(int);
    void setCountdown(int);
    void addKategorie(std::string);

private:
    std::string _spielname="";
    int _rundenanzahl =0;
    int _rundendauer =0;
    int _countdown =0;
    Categories category;


};

#endif // SPIELEINSTELLUNGEN_H

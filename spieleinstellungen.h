#ifndef SPIELEINSTELLUNGEN_H
#define SPIELEINSTELLUNGEN_H
#include <string>
#include <vector>

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
    void setKategorienlListe(std::string);

private:
    std::string _spielname="";
    int _rundenanzahl =0;
    int _rundendauer =0;
    int _countdown =0;
    std::vector<std::string> _kategorienListe;


};

#endif // SPIELEINSTELLUNGEN_H

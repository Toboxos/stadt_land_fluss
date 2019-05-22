#ifndef SPIELER_H
#define SPIELER_H
#include <string>
#include <vector>

class Spieler{


public:
    Spieler(std::string);
    std::string getName();
    int getPunkte();
    int getId();
    void setPunkte(int);
    static int _nextId;
private:
    std::string _name;
    int _punkte = 0;
    int _id=0;


};



#endif // SPIELER_H



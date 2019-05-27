#ifndef SPIELER_H
#define SPIELER_H
#include <string>
#include <vector>

class Spieler{


public:
    Spieler(std::string);

    std::string getName();
    int getId();

    int getPunkte();
    void setPunkte(int);

    std::string getAnswer(int);
    void setAnswer(int,std::string);

    int getCredit(int);
    void setCredit(int,int);

    static int _nextId;
private:
    std::string _name;
    int _punkte = 0;
    int _id=0;
    std::vector<std::string> answers;
    std::vector<int> credits;
};



#endif // SPIELER_H



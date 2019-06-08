#include "spieler.h"

Spieler::Spieler() {

}

Spieler::Spieler(QString name)
{
   _name = name;
   static int _nextId;
   _id = _nextId;
   _nextId ++;
}

QString Spieler::getName()
{
    return _name;
}

int Spieler::getId()
{
    return _id;
}

void Spieler::setConnectionId(unsigned int id){
    connectionId = id;
}

void Spieler::setAnswers(QVector<QString> antworten){
    answers = antworten;
}

unsigned int Spieler::getConnectionId(){
    return connectionId;
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

QString Spieler::getAnswer(int i){
    QString p = answers.value(i);
    return p;
}

void Spieler::setAnswer(unsigned int i, QString a){
    answers.replace(i, a);
}

QVector<int> Spieler::getCredit(){
    QVector<int> p = credits;
    return p;
}

void Spieler::setCredit(int s, int j){
    credits.replace(s,j);
}



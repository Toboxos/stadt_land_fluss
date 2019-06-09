#include "spieler.h"

Spieler::Spieler() {

}

Spieler::Spieler(QString name)
{
   m_name = name;
   static int _nextId;
   m_id = _nextId;
   _nextId ++;
}

QString Spieler::getName()
{
    return m_name;
}

int Spieler::getId()
{
    return m_id;
}

void Spieler::setConnectionId(unsigned int id){
    m_connectionId = id;
}

void Spieler::setAnswers(QVector<QString> antworten){
    m_answers = antworten;
}

unsigned int Spieler::getConnectionId(){
    return m_connectionId;
}

int Spieler::getPunkte()
{
    return m_punkte;
}

void Spieler::setPunkte(int punkte)
{
    m_punkte = punkte;
}

unsigned int Spieler::Categories(){
    unsigned int c = m_answers.size();
    return c;
}

QString Spieler::getAnswer(int i){
    QString p = m_answers.value(i);
    return p;
}

void Spieler::setAnswer(unsigned int i, QString a){
    m_answers.replace(i, a);
}

QVector<int> Spieler::getCredit(){
    QVector<int> p = m_credits;
    return p;
}

void Spieler::setCredit(int s, int j){
    m_credits.replace(s,j);
}



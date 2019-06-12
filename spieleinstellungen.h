#ifndef SPIELEINSTELLUNGEN_H
#define SPIELEINSTELLUNGEN_H
#include <QString>
#include <QVector>
class Spieleinstellungen
{
public:
    Spieleinstellungen();
    int getRundenanzahl();
    int getRundendauer();
    int getCountdown();
    QString getSpielname();
    QVector<QString> getKategorienListe();
    int getKategorieSize();


    void setPlayName(QString);
    void setRoundNumber(int);
    void setRoundTimeLimit(int);
    void setCountdown(int);
    bool addKategorie(QString);
    void setKategories(QVector<QString> Kategorien);
private:
    QString _spielname="";
    int _rundenanzahl =0;
    int _rundendauer =0;
    int _countdown =0;
    QVector<QString> KategorienListe;


};

#endif // SPIELEINSTELLUNGEN_H

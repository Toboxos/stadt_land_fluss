#ifndef SPIELEINSTELLUNGEN_H
#define SPIELEINSTELLUNGEN_H
#include <QString>
#include <QVector>
class Spieleinstellungen
{
public:
    Spieleinstellungen();
    ///
    /// \brief getRundenanzahl returns number of rounds to play.
    /// \return _rundenanzahl
    ///
    int getRundenanzahl();
    ///
    /// \brief getRundendauer returns time limit of each round.
    /// \return _rundendauer
    ///
    int getRundendauer();
    ///
    /// \brief getCountdown returns time the player have to complete their answers when somebody is already ready.
    /// \return _countdown
    ///
    int getCountdown();
    ///
    /// \brief getSpielname returns name of the game.
    /// \return _spielname
    ///
    QString getSpielname();
    ///
    /// \brief getKategorienListe returns kategories.
    /// \return kategorienListe
    ///
    QVector<QString> getKategorienListe();
    ///
    /// \brief getKategorieSize returns the number of kategories
    /// \return kategorienListe.size()
    ///
    int getKategorieSize();

    ///
    /// \brief setPlayName sets the name of the game
    ///
    void setPlayName(QString);
    ///
    /// \brief setRoundNumber sets number of rounds to play.
    ///
    void setRoundNumber(int);
    ///
    /// \brief setRoundTimeLimit time limit of each round.
    ///
    void setRoundTimeLimit(int);
    ///
    /// \brief setCountdown time the player have to complete their answers when somebody is already ready.
    ///
    void setCountdown(int);
    ///
    /// \brief addKategorie add kategories.
    /// \return
    ///
    bool addKategorie(QString);
    ///
    /// \brief setKategories set kategories.
    /// \param Kategorien
    ///
    void setKategories(QVector<QString> Kategorien);
    ///
    /// \brief clearAnserVector set anserVector to NULL
    ///
    void clearAnserVector();
private:
    QString _spielname="";
    int _rundenanzahl =0;
    int _rundendauer =0;
    int _countdown =0;
    QVector<QString> KategorienListe;


};

#endif // SPIELEINSTELLUNGEN_H

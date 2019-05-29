#pragma once
#include <stdint.h>
#include <iostream>
#include <QVector>
#include <stdlib.h>
#include <QObject>
#include <QString>

#include "Network/serversocket.h"
#include "antworten.h"
#include "spieler.h"
#include "punkte.h"

#include "Network/Packets/playerjoinpacket.h"
#include "Network/Packets/playerlistpacket.h"
#include "Network/serversocket.h"
#include "spieleinstellungen.h"


using namespace std;

class CLogik : public QObject {
    Q_OBJECT
public:
    /**
     * @brief CLogik erstellt ein CLogik-Objekt
     */
    CLogik();


    int createPlayer(QString);


    /**
     * @brief sortAnswers sortiert Antworten nach Kategorien
     * @param category Anzahl Kategorien
     * @return QVector<QString> mit Antworten für Kategorie
     */
    QVector<QString> sortAnswers(unsigned int category);

    /**
     * @brief vergibt die Punkte für eine Kategorie
     * @param category Anzahl Kategorien
     * @return QVector mit Punkten für Kategorie
     */
    QVector<int> awardPoints(unsigned int category);

    /**
     * @brief regelt die Punktevergabe für eine Runde
     */
    void Punktevergabe();

    /**
     * @brief ordnet die Spieler nach Gesamtpunktzahl
     * @return QVector mit Spielernamen nach Platzierung geordnet
     */
    QVector<QString> getWinner();

    /**
     * @brief zufälliger Buchstabe für Runde, wiederholt sich alle 26 Runden
     * @return Anfangsbuchstabe für Runde
     */
    char getLetter();

    Spieleinstellungen* getSpieleinstellungen();
    QVector<Spieler>* getSpielerListe();
    void openHostSpielEinstellungen();
    void openKategorieEingabe();
    void openSpielerWarteRaum();

public slots:
    /**
     * @brief nimmt Signal mit Packet entgegen, erstellt neues Spielerobjekt und speichert die VerbindungsID ab
     * @param packet
     * @param id
     */
    void spieler_beitritt(PlayerJoinPacket packet, unsigned int id);
	

private:
    QVector<Spieler> players;
    QVector<antworten> answers;
    QVector<punkte> points;
    char letters[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char usedLetters[26];
    ServerSocket serverSocket;

    QVector<Spieler> _spielerListe;
    Spieleinstellungen  _einstellung ;


};

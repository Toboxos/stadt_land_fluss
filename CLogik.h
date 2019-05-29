#pragma once
#include <stdint.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <QObject>

#include "Network/serversocket.h"
#include "antworten.h"
#include "spieler.h"
#include "punkte.h"

#include "Network/Packets/playerjoinpacket.h"
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
    int createPlayer(std::string);

    /**
     * @brief sortAnswers sortiert Antworten nach Kategorien
     * @param category Anzahl Kategorien
     * @return vector<string> mit Antworten für Kategorie
     */
    vector<std::string> sortAnswers(unsigned int category);

    /**
     * @brief vergibt die Punkte für eine Kategorie
     * @param category Anzahl Kategorien
     * @return vector mit Punkten für Kategorie
     */
    vector<int> awardPoints(unsigned int category);

    /**
     * @brief regelt die Punktevergabe für eine Runde
     */
    void Punktevergabe();

    /**
     * @brief ordnet die Spieler nach Gesamtpunktzahl
     * @return vector mit Spielernamen nach Platzierung geordnet
     */
    vector<std::string> getWinner();

    /**
     * @brief zufälliger Buchstabe für Runde, wiederholt sich alle 26 Runden
     * @return Anfangsbuchstabe für Runde
     */
    char getLetter();

public slots:
    /**
     * @brief nimmt Signal mit Packet entgegen, erstellt neues Spielerobjekt und speichert die VerbindungsID ab
     * @param packet
     * @param id
     */
    void spieler_beitritt(PlayerJoinPacket packet, unsigned int id);
	

private:
    std::vector<Spieler> players;
    std::vector<antworten> answers;
    std::vector<punkte> points;
    char letters[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char usedLetters[26];
    ServerSocket serverSocket;
};

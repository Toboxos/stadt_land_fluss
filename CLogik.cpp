#include "CLogik.h"
#include "CSpieler.h"

//erstellt einen Spieler
void CLogik::createPlayer(string n, int c) {
	CSpieler spieler(n, c);
	//speichern in vector players
}

//vergibt die Punkte der Runde
void CLogik::awardPoints() {
	//klappt schon 
}

//gibt den Spieler mit der h�chsten Gesamtpunktzahl zur�ck
string CLogik::getWinner() {
	int n;
	int max;
	string name;

    n = players.size();
    max = players[0].getPoints();
    name = players[0].getName();
	//for number: if Punktestand gr��er max dann aktualisieren
	return name;
}

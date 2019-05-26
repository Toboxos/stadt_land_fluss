#include "CSpieler.h"

CSpieler::CSpieler(string n, int c) {
	points = 0;
	name = n;
    answers.resize(c);
    credit.resize(c);
}

//gibt momentanen Punktestand des Spielers zurück
int CSpieler::getPoints() {
	return points;
}

//setzt den Punktestand des Spielers auf Übergabewert
void CSpieler::setPoints(int i) {
	points = i;
}

// gibt den Spielernamen zurück
string CSpieler::getName() {
	return name;
}

//setzt den Spielernamen
void CSpieler::setName(string n) {
	name = n;
}

//gibt die Antwort für Kategorie i raus
string CSpieler::getAnswer(int i){
	//return Element der Llste an Stelle i
    return "";
}

//setzt die Antwort für Kategorie i
void CSpieler::setAnswer(int i, string a) {
	//schreibt Antwort a an Stelle i
}

//gibt die Punktezahl für Kategorie i aus
int CSpieler::getCredit(int i) {
	//return Element der Liste an Stelle i
    return 0;
}

//setzt die Punktezahl für Kategorie i
void CSpieler::setCredit(int i, int j) {
	//schreibt an Stelle i die Punktezahl j
}

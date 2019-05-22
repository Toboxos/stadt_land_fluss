#include "CSpieler.h"

CSpieler::CSpieler(string n, int c) {
	points = 0;
	name = n;
	answers.resize c;
	credit.resize c;
}

//gibt momentanen Punktestand des Spielers zurück
CSpieler::getPoints() {
	return points;
}

//setzt den Punktestand des Spielers auf Übergabewert
CSpieler::setPoints(int i) {
	points = i;
}

// gibt den Spielernamen zurück
CSpieler::getName() {
	return name;
}

//setzt den Spielernamen
CSpieler::setName(string n) {
	name = n;
}

//gibt die Antwort für Kategorie i raus
CSpieler::getAnswer(int i){
	//return Element der Llste an Stelle i
}

//setzt die Antwort für Kategorie i
CSpieler::setAnswer(int i, string a) {
	//schreibt Antwort a an Stelle i
}

//gibt die Punktezahl für Kategorie i aus
CSpieler::getCredit(int i) {
	//return Element der Liste an Stelle i
}

//setzt die Punktezahl für Kategorie i
CSpieler::setCredit(int i, int j) {
	//schreibt an Stelle i die Punktezahl j
}
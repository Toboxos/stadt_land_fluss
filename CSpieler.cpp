#include "CSpieler.h"

CSpieler::CSpieler(string n, int c) {
	points = 0;
	name = n;
	answers.resize c;
	credit.resize c;
}

//gibt momentanen Punktestand des Spielers zur�ck
CSpieler::getPoints() {
	return points;
}

//setzt den Punktestand des Spielers auf �bergabewert
CSpieler::setPoints(int i) {
	points = i;
}

// gibt den Spielernamen zur�ck
CSpieler::getName() {
	return name;
}

//setzt den Spielernamen
CSpieler::setName(string n) {
	name = n;
}

//gibt die Antwort f�r Kategorie i raus
CSpieler::getAnswer(int i){
	//return Element der Llste an Stelle i
}

//setzt die Antwort f�r Kategorie i
CSpieler::setAnswer(int i, string a) {
	//schreibt Antwort a an Stelle i
}

//gibt die Punktezahl f�r Kategorie i aus
CSpieler::getCredit(int i) {
	//return Element der Liste an Stelle i
}

//setzt die Punktezahl f�r Kategorie i
CSpieler::setCredit(int i, int j) {
	//schreibt an Stelle i die Punktezahl j
}
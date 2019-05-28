#include "CLogik.h"
#include "spieler.h"
#include "antworten.h"
#include "punkte.h"

//erstellt einen Spieler und gibt ID zurück
int CLogik::createPlayer(string name) {
    Spieler spieler(name);
	//speichern in vector players
    players[spieler.getId()] = spieler;
    return spieler.getId();
}

//sortiert die Antworten in Kategorien nach Spieler
vector<std::string> CLogik::sortAnswers(unsigned int category) {
    unsigned int anzahl = players.size();
    vector<std::string> antworten;

    for (unsigned int var = 0; var < anzahl; ++var) {
        antworten[var] = players[var].getAnswer(category);
    }

   return antworten;
}

void CLogik::Punktevergabe(){
    unsigned int categories = players[0].Categories();

    //sortiert Antworten nach Kategorie
    for (unsigned int var = 0;var < categories; ++var) {
        answers[var]= sortAnswers(var);
    }

    //gibt Punkte für Kategorie
    for (unsigned int n = 0; n < categories; ++n){
        points[n] = awardPoints(n);
    }

    unsigned int anzahl = players.size();
    for (unsigned int m = 0; m < anzahl; ++m){
        Spieler player = players[m];
        int speicher = 0;

        //speichert die Punkte für einen Spieler in der aktuellen Runde
        for (unsigned int l = 0; l < categories; ++l){
            vector<int> punkte = points[l].getPunkte();
            player.setCredit(l, punkte[l]);
            speicher = speicher + punkte[l];
        }

        //aktualisiert den Gesamtpunktespeicher des Spielers
        int jetzt = player.getPunkte();
        player.setPunkte(jetzt + speicher);
    }

}

//gibt die Punkte für eine Kategorie
std::vector<int> CLogik::awardPoints(unsigned int category){
    vector<std::string> antworten = answers[category].getAntworten();
    unsigned int anzahl = antworten.size();
    vector<int> points;
    int sum = 0;

    for (unsigned int var = 0; var < anzahl; ++var) {
        if (antworten[var] == "empty"){
            points[var] = 0;
        }
        else {
            points[var] = 10;
        }
        for (unsigned int n = 0; n < anzahl; ++n) {
            if (n != var){
                if (antworten[var] == antworten [n]){
                    points[var] = 5;
                }
            }
        }
    }

    for (unsigned int v = 0; v < anzahl; ++v){
        for (unsigned int z = 0; z < anzahl; ++z){
            sum = sum + points[z];
        }
        if (sum == points[v]){
            points[v] = 20;
        }
    }

    return points;
}


//gibt die Spieler nach Gesamtpunktzahl geordnet zurück
vector<std::string> CLogik::getWinner() {
    unsigned int anzahl = players.size();
    vector<std::string> names;
    vector<int> allPoints;

    for (unsigned int var = 0; var < anzahl; ++var) {
        allPoints[var] = players[var].getPunkte();
    }

    bool sorted = false;

    while(!sorted){
        sorted = true;

        for (unsigned int i = 0;i < anzahl; ++i) {

            if (allPoints[i]<allPoints[i+1]){
                int temp = allPoints[i];
                allPoints[i] = allPoints[i+1];
                allPoints[i+1] = temp;
            }

            sorted = false;
        }
    }

    for (unsigned int n = 0; n < anzahl; ++n) {
        for (unsigned int p = 0; p < anzahl; ++p){
            if (allPoints[n] = players[p].getPunkte()){
                names[n] = players[p].getName();
            }
        }


    }
    return names;
}

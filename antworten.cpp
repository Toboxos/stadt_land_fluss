#include "antworten.h"

antworten::antworten(vector<std::string> a){
    answers = a;
}

vector<std::string> antworten::getAntworten(){
    return answers;
}

void antworten::setAntworten(std::string a,int i){
    answers[i] = a;
}

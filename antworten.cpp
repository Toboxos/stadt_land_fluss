#include "antworten.h"

antworten::antworten(vector<QString> a){
    answers = a;
}

antworten::~antworten() {

}

vector<QString> antworten::getAntworten(){
    return answers;
}

void antworten::setAntworten(QString a,int i){
    answers[i] = a;
}

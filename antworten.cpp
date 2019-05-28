#include "antworten.h"

antworten::antworten(vector<std::string> a){
    answers = a;
}

antworten::~antworten() {

}

vector<std::string> antworten::getAntworten(){
    return answers;
}

void antworten::setAntworten(std::string a,int i){
    answers[i] = a;
}

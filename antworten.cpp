#include "antworten.h"


antworten::antworten(){

};

antworten::antworten(QVector<QString> a){
    answers = a;
   }


QVector<QString> antworten::getAntworten(){
    return answers;
}

void antworten::setAntworten(QString a,int i){
    answers[i] = a;
}

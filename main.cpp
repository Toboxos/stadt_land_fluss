#include <QApplication>
#include "spielstart.h"
#include "einwand.h"
#include "clientlogic.h"
#include "spielstart.h"

#include "CLogik.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ClientLogic clientLogic;

    //Einwand r;
    //r.exec();

    //SpielStart w;


    // w.exec();

    return a.exec();
}

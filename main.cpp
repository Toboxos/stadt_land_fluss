#include <QApplication>
#include "spielstart.h"
#include "einwand.h"
#include "clientlogic.h"
#include "spielstart.h"

#include "Examples/networkexample.h"
#include "CLogik.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    CLogik serverLogik;
    ClientLogic clientLogic;

    NetworkExample e;

    //Einwand r;
    //r.exec();

    //SpielStart w;


    // w.exec();

    return a.exec();
}

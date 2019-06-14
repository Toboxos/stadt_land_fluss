#include <QApplication>
#include "spielstart.h"
#include "clientlogic.h"
#include "spielstart.h"

#include "serverlogic.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ClientLogic clientLogic;
    return a.exec();
}

#include <QApplication>
#include "spielstart.h"

#include "Examples/networkexample.h"
#include "CLogik.h"

std::vector<Spieler> _spielerListe;
Spieleinstellungen  *_einstellung = new Spieleinstellungen();
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    CLogik serverLogik;
    NetworkExample e;

    SpielStart w;

    w.exec();

    return a.exec();
}

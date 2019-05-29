#ifndef SPIELERWARTERAUM_H
#define SPIELERWARTERAUM_H

#include <QDialog>
#include "CLogik.h"
#include "spieler.h"
namespace Ui {
class SpielerWarteRaum;
}

class SpielerWarteRaum : public QDialog
{
    Q_OBJECT

public:
   explicit SpielerWarteRaum(QWidget *parent = nullptr, CLogik *serverLogic= nullptr);
    ~SpielerWarteRaum();

private slots:
    void on_buttonWeiter_clicked();
    void onPlayerJoined(Spieler newPlayer);

private:
    Ui::SpielerWarteRaum *ui;
    CLogik *_serverLogic;
    void createTable();
};

#endif // SPIELERWARTERAUM_H

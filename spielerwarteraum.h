#ifndef SPIELERWARTERAUM_H
#define SPIELERWARTERAUM_H

#include <QDialog>
#include "spieler.h"
class CLogik;
namespace Ui {
class SpielerWarteRaum;
}

class SpielerWarteRaum : public QDialog
{
    Q_OBJECT

public:
   explicit SpielerWarteRaum(QWidget *parent = nullptr, CLogik *serverLogic= nullptr);
    ~SpielerWarteRaum();
    void showPlayer();

private slots:
    void on_buttonWeiter_clicked();

private:
    Ui::SpielerWarteRaum *ui;
    CLogik *_serverLogic;
    void createTable();
};

#endif // SPIELERWARTERAUM_H

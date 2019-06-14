#ifndef SPIELERWARTERAUM_H
#define SPIELERWARTERAUM_H

#include <QDialog>
#include "spieler.h"
class ServerLogic;
namespace Ui {
class SpielerWarteRaum;
}

class SpielerWarteRaum : public QDialog
{
    Q_OBJECT

public:
   explicit SpielerWarteRaum(QWidget *parent = nullptr, ServerLogic *serverLogic= nullptr);
    ~SpielerWarteRaum();
    void showPlayer();

private slots:
    void on_buttonWeiter_clicked();
private:
    Ui::SpielerWarteRaum *ui;
    ServerLogic *_serverLogic;
    void createTable();
};

#endif // SPIELERWARTERAUM_H

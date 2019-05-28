#ifndef SPIELERWARTERAUM_H
#define SPIELERWARTERAUM_H

#include <QDialog>
#include "clientlogic.h"

namespace Ui {
class SpielerWarteRaum;
}

class SpielerWarteRaum : public QDialog
{
    Q_OBJECT

public:
    explicit SpielerWarteRaum(QWidget *parent = nullptr,ClientLogic *clientLogic= nullptr);
    ~SpielerWarteRaum();

private slots:
    void on_buttonWeiter_clicked();

private:
    Ui::SpielerWarteRaum *ui;
    ClientLogic *_clientLogic;
};

#endif // SPIELERWARTERAUM_H

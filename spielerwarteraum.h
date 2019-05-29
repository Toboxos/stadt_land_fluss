#ifndef SPIELERWARTERAUM_H
#define SPIELERWARTERAUM_H

#include <QDialog>
#include "CLogik.h"

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

private:
    Ui::SpielerWarteRaum *ui;
    CLogik *_serverLogic;
};

#endif // SPIELERWARTERAUM_H

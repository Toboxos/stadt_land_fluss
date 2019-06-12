#ifndef KATEGORIEEINGABE_H
#define KATEGORIEEINGABE_H

#include "serverlogic.h"

#include <QDialog>

namespace Ui {
class Kategorieeingabe;
}

class Kategorieeingabe : public QDialog
{
    Q_OBJECT

public:

    explicit Kategorieeingabe(QWidget *parent = nullptr,ServerLogic *serverLogic= nullptr);

    ~Kategorieeingabe();

private slots:
    void on_buttonWeiter_clicked();

    void on_buttonZurueck_clicked();

    void on_buttonHinzufuegen_clicked();

    void on_einlesenKategorie_textEdited(const QString &arg1);

private:
    Ui::Kategorieeingabe *ui;
    ServerLogic *_serverLogic;
    int kategorieZaehler =2;
};

#endif // KATEGORIEEINGABE_H

#ifndef KATEGORIEEINGABE_H
#define KATEGORIEEINGABE_H
#include "clientlogic.h"

#include <QDialog>

namespace Ui {
class Kategorieeingabe;
}

class Kategorieeingabe : public QDialog
{
    Q_OBJECT

public:
    explicit Kategorieeingabe(QWidget *parent = nullptr,ClientLogic *clientLogic= nullptr);
    ~Kategorieeingabe();

private slots:
    void on_buttonWeiter_clicked();

    void on_buttonZurueck_clicked();

    void on_buttonHinzufuegen_clicked();

    void on_einlesenKategorie_textEdited(const QString &arg1);

private:
    Ui::Kategorieeingabe *ui;
    ClientLogic *_clientLogic;
    int kategorieZaehler =2;
};

#endif // KATEGORIEEINGABE_H

#ifndef KATEGORIEEINGABE_H
#define KATEGORIEEINGABE_H
<<<<<<< HEAD
#include "CLogik.h"

=======
#include "clientlogic.h"
#include "CLogik.h"
>>>>>>> 19ff8b37ba9f9396c37e81a4829ef1b1c1faa500
#include <QDialog>

namespace Ui {
class Kategorieeingabe;
}

class Kategorieeingabe : public QDialog
{
    Q_OBJECT

public:
<<<<<<< HEAD
    explicit Kategorieeingabe(QWidget *parent = nullptr,CLogik *serverLogic= nullptr);
=======
    explicit Kategorieeingabe(QWidget *parent = nullptr,ClientLogic *clientLogic= nullptr, CLogik *serverlogic= nullptr);
>>>>>>> 19ff8b37ba9f9396c37e81a4829ef1b1c1faa500
    ~Kategorieeingabe();

private slots:
    void on_buttonWeiter_clicked();

    void on_buttonZurueck_clicked();

    void on_buttonHinzufuegen_clicked();

    void on_einlesenKategorie_textEdited(const QString &arg1);

private:
    Ui::Kategorieeingabe *ui;
    CLogik *_serverLogic;
    int kategorieZaehler =2;
};

#endif // KATEGORIEEINGABE_H

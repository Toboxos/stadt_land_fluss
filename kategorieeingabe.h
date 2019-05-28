#ifndef KATEGORIEEINGABE_H
#define KATEGORIEEINGABE_H

#include <QDialog>

namespace Ui {
class Kategorieeingabe;
}

class Kategorieeingabe : public QDialog
{
    Q_OBJECT

public:
    explicit Kategorieeingabe(QWidget *parent = nullptr);
    ~Kategorieeingabe();

private slots:
    void on_buttonWeiter_clicked();

    void on_buttonZurueck_clicked();

    void on_buttonHinzufuegen_clicked();

    void on_inputCategorie_textEdited(const QString &arg1);



private:
    Ui::Kategorieeingabe *ui;
    int kategorieZaehler =2;
};

#endif // KATEGORIEEINGABE_H

#ifndef KATEGORIEEINGABE_H
#define KATEGORIEEINGABE_H

#include "CLogik.h"

#include <QDialog>

namespace Ui {
class Kategorieeingabe;
}

class Kategorieeingabe : public QDialog
{
    Q_OBJECT

public:

    explicit Kategorieeingabe(QWidget *parent = nullptr,CLogik *serverLogic= nullptr);

    ~Kategorieeingabe();

private slots:
    void on_buttonWeiter_clicked();
    void on_buttonZurueck_clicked();
    ///
    /// \brief on_buttonHinzufuegen_clicked Die hinzugefügte Kategorie wird in der Tabelle angezeigt. Die kategorien werden in den Spieleinstellungen gespeichert.
    ///
    void on_buttonHinzufuegen_clicked();
    ///
    /// \brief on_einlesenKategorie_textEdited erst wenn eine Kategorie geschrieben wurde, wird der button Hinzufügen enabled
    /// \param arg1
    ///
    void on_einlesenKategorie_textEdited(const QString &arg1);

private:
    Ui::Kategorieeingabe *ui;
    CLogik *_serverLogic;
    int kategorieZaehler =2;
};

#endif // KATEGORIEEINGABE_H

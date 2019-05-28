#ifndef HOSTSPIELEINSTELLUNGEN_H
#define HOSTSPIELEINSTELLUNGEN_H

#include "spielerliste.h"
#include "spieler.h"
#include <QDialog>

namespace Ui {
class HostSpielEinstellungen;
}

class HostSpielEinstellungen : public QDialog
{
    Q_OBJECT

public:
    explicit HostSpielEinstellungen(QWidget *parent = nullptr);
    ~HostSpielEinstellungen();

private slots:
    void on_buttonWeiter_clicked();

    void on_buttonZurueck_clicked();

    void on_checkBoxUnendlich_stateChanged(int arg1);

    void on_eingegebenerSpielname_textEdited(const QString &arg1);

    void on_eingabeRunden_textEdited(const QString &arg1);

    void on_eingabeZeitlimit_textEdited(const QString &arg1);

    void on_EingabeZeitNachAntwort_textEdited(const QString &arg1);

private:
    bool checkBoxChecked= false;
    Ui::HostSpielEinstellungen *ui;
};

#endif // HOSTSPIELEINSTELLUNGEN_H

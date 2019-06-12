#ifndef HOSTSPIELEINSTELLUNGEN_H
#define HOSTSPIELEINSTELLUNGEN_H

#include "spielerliste.h"
#include "spieler.h"
#include <QDialog>
#include "serverlogic.h"

namespace Ui {
class HostSpielEinstellungen;
}

class HostSpielEinstellungen : public QDialog
{
    Q_OBJECT

public:
    explicit HostSpielEinstellungen(QWidget *parent = nullptr,ServerLogic *serverLogic= nullptr);
    ~HostSpielEinstellungen();

private slots:
    void on_buttonNext_clicked();



    void on_checkBoxUnendlich_stateChanged(int arg1);

    void on_inputGameName_textEdited(const QString &arg1);

private:

    ServerLogic *_ServerLogic;
    bool checkBoxChecked= false;
    ServerLogic *_serverLogic;
    Ui::HostSpielEinstellungen *ui;
};

#endif // HOSTSPIELEINSTELLUNGEN_H

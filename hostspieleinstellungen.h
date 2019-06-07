#ifndef HOSTSPIELEINSTELLUNGEN_H
#define HOSTSPIELEINSTELLUNGEN_H

#include "spielerliste.h"
#include "spieler.h"
#include "CLogik.h"
#include <QDialog>
#include"CLogik.h"

namespace Ui {
class HostSpielEinstellungen;
}

class HostSpielEinstellungen : public QDialog
{
    Q_OBJECT

public:
    explicit HostSpielEinstellungen(QWidget *parent = nullptr,CLogik *serverLogic= nullptr);
    ~HostSpielEinstellungen();

private slots:
    void on_buttonNext_clicked();



    void on_checkBoxUnendlich_stateChanged(int arg1);

    void on_inputGameName_textEdited(const QString &arg1);

private:

    CLogik *_cLogik;
    bool checkBoxChecked= false;
    CLogik *_serverLogic;
    Ui::HostSpielEinstellungen *ui;
};

#endif // HOSTSPIELEINSTELLUNGEN_H

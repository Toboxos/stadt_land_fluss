#ifndef HOSTSPIELEINSTELLUNGEN_H
#define HOSTSPIELEINSTELLUNGEN_H

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
    ///
    /// \brief on_buttonNext_clicked Sobald auf den ButtonWeiter geklickt wird, werden die
    /// Werte übernommen und in Vaiablen geschrieben.
    /// Außerdem wird überprüft, dass keine Buchstaben und Werte
    ///  kleiner als Null eingegeben wurden.
    ///
    void on_buttonNext_clicked();


    ///
    /// \brief on_checkBoxUnendlich_stateChanged checkBoxChecked = true: Spiel soll unendlich lang gehen
    /// checkBoxChecked = false: checkBox ist nicht gechekt und fester Wert wird genommen.
    /// \param arg1
    ///
    void on_checkBoxUnendlich_stateChanged(int arg1);
    ///
    /// \brief on_inputGameName_textEdited Button weiter wird erst anabeld wenn Spilname geändert wurde.
    /// \param arg1
    ///
    void on_inputGameName_textEdited(const QString &arg1);

private:

    ServerLogic *_ServerLogic;
    bool checkBoxChecked= false;
    ServerLogic *_serverLogic;
    Ui::HostSpielEinstellungen *ui;
};

#endif // HOSTSPIELEINSTELLUNGEN_H

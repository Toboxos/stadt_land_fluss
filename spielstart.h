#ifndef SPIELSTART_H
#define SPIELSTART_H
#include "ui_spielstart.h"
#include "hostspieleinstellungen.h"
#include "spieler.h"
#include "clientlogic.h"
#include <string>
#include <QDialog>

namespace Ui {
class SpielStart;
}

class SpielStart : public QDialog
{
    Q_OBJECT

public:
    explicit SpielStart(QWidget *parent = nullptr, ClientLogic *clientLogic= nullptr);
    ~SpielStart();

private slots:
    void on_buttonHost_clicked();


    void on_NameEingabe_textEdited(const QString &arg1);

    void on_NameEingabe_returnPressed();

    void on_buttonBeitreten_clicked();

private:
    Ui::SpielStart *ui;
    ClientLogic *_clientLogic;
};

#endif // SPIELSTART_H

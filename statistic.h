#ifndef STATISTIC_H
#define STATISTIC_H
#include "clientlogic.h"
#include <QDialog>

namespace Ui {
class Statistic;
}

class Statistic : public QDialog
{
    Q_OBJECT

public:
    explicit Statistic(QWidget *parent = nullptr,ClientLogic *clientLogic= nullptr,QVector<QString> *winner = nullptr);
    ~Statistic();

private:
    Ui::Statistic *ui;
    ClientLogic *_clientLogic;
};

#endif // STATISTIC_H

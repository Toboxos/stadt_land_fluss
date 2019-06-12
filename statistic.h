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
    ///
    /// \brief Statistic display scores.
    /// \param parent
    /// \param clientLogic
    /// \param winner
    /// \param points
    ///
    explicit Statistic(QWidget *parent = nullptr,ClientLogic *clientLogic= nullptr,QVector<QString> *winner = nullptr, QVector<int> *points = nullptr);
    ~Statistic();

private slots:
    ///
    /// \brief on_buttonEnd_clicked end of game.
    ///
    void on_buttonEnd_clicked();

private:
    Ui::Statistic *ui;
    ClientLogic *_clientLogic;
};

#endif // STATISTIC_H

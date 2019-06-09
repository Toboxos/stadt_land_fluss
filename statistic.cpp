#include "statistic.h"
#include "ui_statistic.h"

Statistic::Statistic(QWidget *parent,ClientLogic *clientLogic, QVector<QString> *winner, QVector<int> *points) :
    QDialog(parent),
    ui(new Ui::Statistic)
{
    /*QVector<QString> test;
    test.push_back("hansi");
    test.push_back("masi");
    test.push_back("hermann");*/
    ui->setupUi(this);
    _clientLogic = clientLogic;

    for (int count= 0; count < winner->length(); count++)
    {
        qDebug() << *winner << endl;
        qDebug() << *points << endl;
        ui->tableWinner->setRowCount(count+1);
        QString platz = "Platz" + QString::number(count+1);
        ui->tableWinner->setVerticalHeaderItem(count, new QTableWidgetItem(platz, count));
        ui->tableWinner->setItem(count, 0, new QTableWidgetItem(winner->at(count)));
        ui->tableWinner->setItem(count, 1, new QTableWidgetItem(QString::number(points->at(count))));
    }

}

Statistic::~Statistic()
{
    delete ui;
}

void Statistic::on_buttonEnd_clicked()
{
    qApp->quit();
}

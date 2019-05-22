#include "startpunkt.h"
#include "ui_startpunkt.h"
#include "spielstart.h"

StartPunkt::StartPunkt(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StartPunkt)
{
    ui->setupUi(this);
    SpielStart spielStart;
    spielStart.exec();
}

StartPunkt::~StartPunkt()
{
    delete ui;
}

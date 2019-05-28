#include "einwand.h"
#include "ui_einwand.h"
#include "QLabel"
#include "QLineEdit"
#include "QButtonGroup"
Einwand::Einwand(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Einwand)
{


    ui->setupUi(this);
    //createTable();

}

//void Einwand::packetangekommen;
Einwand::~Einwand()
{
    delete ui;
}


/*
void Einwand::createTable()
{
ui->tableEinwand->setRowCount()
}*/

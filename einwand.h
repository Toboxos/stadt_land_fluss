#ifndef EINWAND_H
#define EINWAND_H

#include <QDialog>

namespace Ui {
class Einwand;
}

class Einwand : public QDialog
{
    Q_OBJECT

public:
    explicit Einwand(QWidget *parent = nullptr);
    ~Einwand();

private:
    Ui::Einwand *ui;
    //void createTable();
};

#endif // EINWAND_H

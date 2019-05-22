#ifndef STARTPUNKT_H
#define STARTPUNKT_H

#include <QMainWindow>

namespace Ui {
class StartPunkt;
}

class StartPunkt : public QMainWindow
{
    Q_OBJECT

public:
    explicit StartPunkt(QWidget *parent = nullptr);
    ~StartPunkt();

private:
    Ui::StartPunkt *ui;
};

#endif // STARTPUNKT_H

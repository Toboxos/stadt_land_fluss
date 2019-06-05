#ifndef TEST_H
#define TEST_H

#include <QObject>

class Test : public QObject {
    Q_OBJECT

    public:
        virtual void run() = 0;

    signals:
        void finished();
        void failed(QString Message);
};

#endif // TEST_H

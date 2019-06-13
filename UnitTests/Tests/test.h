#ifndef TEST_H
#define TEST_H

#include <QtTest/QTest>

/**
 * @brief Base class for asynchronous packet tests
 */
class Test : public QObject {
    Q_OBJECT

    public:
        virtual void run() = 0;

    signals:
        /**
         * @brief Called when all test cases finshed
         */
        void finished();

        /**
         * @brief Callend when test case failed
         *
         * @param message   Description what failed
         */
        void failed(QString message);
};

#endif // TEST_H

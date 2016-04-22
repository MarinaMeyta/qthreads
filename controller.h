#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QCoreApplication>
#include <QThread>

class Controller : public QObject
{
    Q_OBJECT
    QThread workerFirstThread;
    QThread workerSecondThread;

public:
    Controller();
    ~Controller();

public slots:
    void some_function();

signals:
    void quit();
};

#endif // CONTROLLER_H

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QCoreApplication>
#include <QThread>
#include <QVector>

class Worker;

class Controller : public QObject
{
    Q_OBJECT
    int threads_counter;
    QVector<QThread*> threads;

public:
    Controller();
    ~Controller();

    void add_task(Worker* task);
    void start_threads();

public slots:
    void stop_threads();

signals:
    void finished();
};

#endif // CONTROLLER_H

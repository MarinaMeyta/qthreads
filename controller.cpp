#include "controller.h"
#include "worker.h"

#include <QDebug>
#include <QThread>
#include <QTimer>
#include <QVector>

Controller::Controller() {}

Controller::~Controller() {}

void Controller::start_threads() {

    // n = tasks.size()
    int n = 3;

    QVector<QThread*> threads(n);
    for (int i = 0; i < n; i++)
    {
        QThread* thread = new QThread();
        Worker* worker = new Worker();
        worker->moveToThread(thread);
        connect(thread, SIGNAL(started()), worker, SLOT(run()));
        connect(thread, SIGNAL(finished()), worker, SLOT(deleteLater()));
        threads[i] = thread;
    }

    for (int i = 0; i < threads.capacity(); i++)
    {
        qDebug() << "Starting " << i << " thread...\n";
        threads[i]->start();
    }

    threads.clear();
    emit quit();
    qDebug() << "Quitting...";
}




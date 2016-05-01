#include "controller.h"
#include "worker.h"

#include <QDebug>
#include <QThread>
#include <QTimer>
#include <QVector>

Controller::Controller()
{
    threads_counter = 0;
}

Controller::~Controller()
{
    qDebug() << "Controller object was destroyed\n";
}

void Controller::add_task(Worker *task)
{
    task->setParent(NULL);
    QThread* thread = new QThread();
    task->moveToThread(thread);
    connect(thread, SIGNAL(started()), task, SLOT(run()));
    connect(task, SIGNAL(finished()), thread, SLOT(quit()));
    connect(task, SIGNAL(finished()), task, SLOT(deleteLater()));
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    connect(thread, SIGNAL(destroyed()), this, SLOT(stop_threads()));

    threads.push_back(thread);
}

void Controller::start_threads()
{
    foreach (QThread* t, threads)
    {
       t->start();
       qDebug() << "thread started\n";
    }
}

//slot for finishing threads
void Controller::stop_threads()
{
    ++threads_counter;

    if (threads_counter == threads.count())
    {
        emit finished();
        qDebug() << "threads are finished\n";
    }
}




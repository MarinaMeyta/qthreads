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
    connect(task, SIGNAL(finished()), thread, SLOT(deleteLater()));
    threads.push_back(thread);
}

void Controller::start_threads()
{
    foreach (QThread* t, threads)
    {
       t->start();
    }
}

//slot for finishing threads
void Controller::stop_threads()
{
    bool all_finished = false;

    while(all_finished != true)
    {
        foreach (QThread* t, threads)
        {
           if (t->isRunning())
           {
//               threads_counter++;
//               qDebug() << "threads_counter++\n";
               qDebug() << "thread is still running\n";
           }
           else {qDebug() << "finished\n";}
        }

//        if (threads_counter == threads.capacity())
//        {
//            all_finished = true;
//            qDebug() << "all finished = true\n";
//        }
    }

//    emit finished();
//    qDebug() << "threads are finished\n";
}




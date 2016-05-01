#include "worker.h"

#include <QDebug>
#include <QThread>
Worker::Worker(): mes("") {}

Worker::~Worker() {}

void Worker::set_message(const QString &message)
{
    this->mes = message;
}

void Worker::run()
{
    for (int i = 0; i < 5; i++)
    {
        qDebug() << "message: " << mes;
//        sleep(2);
    }
    emit finished();
    qDebug() << "finished work\n";
}

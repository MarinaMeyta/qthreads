#include "worker.h"

#include <QDebug>
#include <QThread>
Worker::Worker() {}

Worker::~Worker() {}

void Worker::run()
{
    for (int i = 0; i < 5; i++)
    {
       qDebug() << "message " << (i + 1);
//       QThread::usleep(1000);
    }
    emit finished();
}

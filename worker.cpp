#include "worker.h"

#include <QDebug>

Worker::Worker() {}

Worker::~Worker() {}

void Worker::run()
{
    for (int i = 0; i < 5; i++)
    {
       qDebug() << "message " << (i + 1);
    }
    emit finished();
}

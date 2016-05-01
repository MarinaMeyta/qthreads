/**
  Qt Version: 4.8.6
  Author: Marina Meyta
  2016
  **/

#include "controller.h"
#include "worker.h"

#include <QCoreApplication>
#include <QDebug>

#include <QtGlobal>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

//    qDebug() << "QVersion: " << qVersion();

    qDebug() << "Starting executing...\n";
    // n = tasks.size()

    Worker* a = new Worker();
    a->set_message("aaaaaaa");

    Worker* b = new Worker();
    b->set_message("bbbbbbb");

    Worker* d = new Worker();
    d->set_message("ddddddd");

    Controller* c = new Controller();
    c->add_task(a);
    c->add_task(b);
    c->add_task(d);

    QObject::connect(c, SIGNAL(finished()), &app, SLOT(quit()));
    c->start_threads();

    return app.exec();
}

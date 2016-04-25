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
    Controller c;
    c.start_threads();
//    QObject::connect(&c, SIGNAL(quit()), &app, SLOT(QCoreApplication::exit()));
    return app.exec();
}

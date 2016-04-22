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
    Controller();

    return app.exec();
}

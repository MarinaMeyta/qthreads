#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QCoreApplication>
#include <QThread>

class Controller : public QObject
{
    Q_OBJECT

public:
    Controller();
    ~Controller();

public slots:
    void start_threads();

signals:
    void quit();
};

#endif // CONTROLLER_H

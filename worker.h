#ifndef CHILD_OBJECT_H
#define CHILD_OBJECT_H

#include <QObject>

class Worker : public QObject
{
    Q_OBJECT

public:
    Worker();
    ~Worker();

signals:
    void finished();

public slots:
    void run();
};

#endif // CHILD_OBJECT_H

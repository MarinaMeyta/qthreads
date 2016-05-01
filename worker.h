#ifndef CHILD_OBJECT_H
#define CHILD_OBJECT_H

#include <QObject>
#include <QThread>

class Worker : public QObject
{
    Q_OBJECT

public:
    Worker();
    ~Worker();
    void set_message(const QString &message);

signals:
    void finished();

public slots:
    void run();

private:
    QString mes;
};

#endif // CHILD_OBJECT_H

#ifndef ASYNCTHREAD_H
#define ASYNCTHREAD_H

#include <QThread>
#include <QObject>

class AsyncThread : public QThread
{
protected:
    AsyncThread(QObject* parent = NULL);
    ~AsyncThread();
public:
    static AsyncThread* GetInstance(QObject* parent = NULL);
    virtual void run();
};

#endif // ASYNCTHREAD_H

#ifndef ASYNCTHREAD_H
#define ASYNCTHREAD_H

#include <QThread>
#include <QObject>

class AsyncThread : public QObject
{
    Q_OBJECT
public:
    void start();
    AsyncThread(QObject* parent = NULL);
    ~AsyncThread();
private slots:
    void tmain();
private:
    QThread m_thread;
};

#endif // ASYNCTHREAD_H

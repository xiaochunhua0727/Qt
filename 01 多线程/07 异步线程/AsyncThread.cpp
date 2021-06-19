#include "AsyncThread.h"
#include <QDebug>

AsyncThread::AsyncThread(QObject* parent)
    : QThread(parent)
{

}

AsyncThread::~AsyncThread()
{
    qDebug() << "AsyncThread::~AsyncThread()...";
}

AsyncThread* AsyncThread::GetInstance(QObject* parent)
{
    return new AsyncThread(parent);
}

void AsyncThread::run()
{
    for(int cnt = 0; cnt < 5; ++cnt) {
        qDebug() << "current: " << cnt;
        msleep(1000);
    }
    deleteLater();
}

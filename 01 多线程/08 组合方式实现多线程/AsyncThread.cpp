#include "AsyncThread.h"
#include <QDebug>

void AsyncThread::tmain()
{
    qDebug() << "void AsyncThread::tmain()...";
    for(int cnt = 0; cnt < 10; ++cnt) {
        qDebug() << "current: " << cnt;
    }
    // Qt下,线程默认开启了事件循环机制
    m_thread.quit();
}

void AsyncThread::start()
{
    m_thread.start();
}

AsyncThread::AsyncThread(QObject* parent):QObject(parent)
{
    moveToThread(&m_thread);
    QObject::connect(&m_thread, SIGNAL(started()), this, SLOT(tmain()) );
}

AsyncThread::~AsyncThread()
{
    m_thread.wait();
}

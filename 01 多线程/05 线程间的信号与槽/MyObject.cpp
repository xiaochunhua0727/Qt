#include "MyObject.h"
#include <QDebug>
#include <QThread>

MyObject::MyObject(QObject *parent) :
    QObject(parent)
{
}

void MyObject::getStarted()
{
    qDebug() << "getStarted id = " << QThread::currentThreadId();
}

#include <QtCore/QCoreApplication>
#include <QThread>
#include <QObject>
#include <QDebug>
#include "MyObject.h"

class MyThread : public QThread {
public:
    virtual void run() {
        qDebug() << "son Thread ID:" << QThread::currentThreadId();
        // 开启事件循环机制
        exec();
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    MyThread task1;
    MyObject object1;
    qDebug() << "Father Thread ID:" << QThread::currentThreadId();
    QObject::connect(&task1, SIGNAL(started()), &object1, SLOT(getStarted()));
    task1.moveToThread(&task1);
    object1.moveToThread(&task1);
    task1.start();

    return a.exec();
}

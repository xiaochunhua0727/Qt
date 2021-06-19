#include <QtCore/QCoreApplication>
#include "AsyncThread.h"

void func()
{
    AsyncThread* pTask = AsyncThread::GetInstance();
    pTask->start();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    func();

    return a.exec();
}

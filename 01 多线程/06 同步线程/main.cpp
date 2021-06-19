#include <QtCore/QCoreApplication>
#include <QThread>
#include <QObject>
#include <QDebug>


class MyThread : public QThread {
protected:
    virtual void run() {
        for(int cnt = 0; cnt < 10; ++cnt) {
            qDebug() << "current value: " << cnt;
            msleep(1000);
        }
    }
public:
    ~MyThread() {
        // 等待线程结束，然后才释放对象
        wait();
    }
};

void func() {
    MyThread task;
    task.start();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    func();

    return a.exec();
}

#include <QtCore/QCoreApplication>
#include <QThread>
#include <QDebug>

class Task : public QThread {
public:
    Task() { m_isStop = false; }
    void Stop() { m_isStop = true; }
protected:
    virtual void run() {
        qDebug() << "Thread begin..";
        for(int cnt = 0; !m_isStop && (cnt < 5); ++cnt) {
            qDebug() << objectName() << cnt;
            msleep(5);
        }
        qDebug() << "Thread end...";
    }
private:
    bool m_isStop;
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Task task1;
    task1.setObjectName("t");
    task1.start();
    // 加入循环，让子线程打印出部分数据
    for(int cnt = 0; cnt < 30000000; ++cnt) {}
    // 接受子线程
    task1.Stop();

    return a.exec();
}

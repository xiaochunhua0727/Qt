#include <QtCore/QCoreApplication>
#include <QThread>
#include <QDebug>
#include <QString>
#include <QMutex>
#include <QSemaphore>

static QString g_store;
static QSemaphore sem(1);

volatile int count = 0;

class Producer : public QThread {
protected:
    virtual void run() {

        while(true) {
            sem.acquire();
            g_store.append(QString::number( (++count) % 10 ));
            qDebug() << objectName() << " : " << g_store;
            sem.release();
            msleep(1);
        }
    }
};

class Customer : public QThread {
protected:
    virtual void run() {
        while(true) {
            sem.acquire();
            while(g_store.size()) {
                // 消费者消费一个元素
                g_store.remove(0, 1);
                qDebug() << objectName() << " : " << g_store;
            }
            sem.release();
            msleep(1);
        }
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Producer P1,P2,P3;
    Customer C1,C2;
    P1.setObjectName("Producer1");
    P2.setObjectName("Producer2");
    P3.setObjectName("Producer3");
    C1.setObjectName("Customer1");
    C2.setObjectName("Customer2");
    P1.start();
    P2.start();
    P3.start();
    C1.start();
    C2.start();

    return a.exec();
}

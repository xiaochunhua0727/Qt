#include <QtCore/QCoreApplication>
#include <QThread>
#include <QDebug>

class Calculator : public QThread {
public:
    Calculator(int begin,int end)
        :m_begin(begin), m_end(end),m_result(0) {}

    virtual void run() {
        for(int cnt = m_begin; cnt < m_end; ++cnt) {
            m_result += cnt;
        }
    }

    int getResult() {
        return m_result;
    }
private:
    int m_begin;
    int m_end;
    int m_result;
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    // ���������Ϊ������: ����0-100���ۼӼ�101��200����Ӻ�
    Calculator task1(0, 100);
    Calculator task2(101, 200);
    task1.start();
    task2.start();
    // ���߳��������ȴ����߳�ִ�н���
    task1.wait();
    task2.wait();

    qDebug() << "result: " << task1.getResult() + task2.getResult();

    return a.exec();
}

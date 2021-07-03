#include <QtCore/QCoreApplication>
#include <QHash>
#include <QString>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    // ����Ԫ�ز��뷽ʽ������map1[23] = "JH"���ֲ��뷽ʽ
    QHash<int, QString> hash;
    hash.insert(12,"Francis");
    hash.insert(4,"C++");
    hash.insert(34, "Hello");

    // ����mapԪ��ʱ����������Ĭ��ֵ
    QString value = hash.value(12,"Qt");
    qDebug() << "value: " << value;

    // ����
    QHash<int,QString>::iterator ite = hash.begin();
    for( ; ite != hash.end(); ++ite ) {
        qDebug() << ite.key() << " " << ite.value();
    }

    return a.exec();
}

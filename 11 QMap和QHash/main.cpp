#include <QtCore/QCoreApplication>
#include <QHash>
#include <QString>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    // 建议元素插入方式，避免map1[23] = "JH"这种插入方式
    QHash<int, QString> hash;
    hash.insert(12,"Francis");
    hash.insert(4,"C++");
    hash.insert(34, "Hello");

    // 建议map元素时，建议设置默认值
    QString value = hash.value(12,"Qt");
    qDebug() << "value: " << value;

    // 采用
    QHash<int,QString>::iterator ite = hash.begin();
    for( ; ite != hash.end(); ++ite ) {
        qDebug() << ite.key() << " " << ite.value();
    }

    return a.exec();
}

#include <QtCore/QCoreApplication>
#include <QBuffer>
#include <QByteArray>
#include <QIODevice>
#include <QDataStream>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QByteArray bytes;
    QBuffer buffer(&bytes);
    // 向缓冲区中写入数据
    if( buffer.open(QIODevice::WriteOnly) ) {
        QDataStream stream(&buffer);
        stream << QString("Q.T.SoftWare");
        stream << 3.14;

        buffer.close();
    }

    if( buffer.open(QIODevice::ReadOnly) ) {
        QDataStream stream(&buffer);
        QString dt;
        double dValue;
        stream >> dt;
        stream >> dValue;
        qDebug() << dt << " " << dValue;

        buffer.close();
    }

    return a.exec();
}

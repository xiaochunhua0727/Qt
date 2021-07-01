#include <QtCore/QCoreApplication>
#include <QFile>
#include <QDebug>
#include <QIODevice>

void textStream(QString path)
{
    QFile file(path);
    if(file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << "D.T.SoftWare" << endl;
        out << "Result: " << endl;
        out << 5 << " * " << 6 << " = " << 30;
        file.close();
    }

    if(file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        QString lineText;
        while(!in.atEnd()) {
            lineText = in.readLine();
            qDebug() << "line: " << lineText;
        }
    }

    return ;
}

void dataStream(QString path)
{
    QFile file(path);
    // 数据输入到文件时,数据须有类型
    if( file.open(QIODevice::WriteOnly) ) {
        QDataStream out(&file);
        out.setVersion(QDataStream::Qt_4_7);
        out << QString("D.T.Software");
        out << QString("Result: ");
        out << 3.14;
        file.close();
    }

    if( file.open(QIODevice::ReadOnly) ) {
        QDataStream in(&file);
        in.setVersion(QDataStream::Qt_4_7);
        QString dt;
        QString result;
        double dvalue;
        in >> dt;
        in >> result;
        in >> dvalue;
        qDebug() << dt << " " << result << " " << dvalue;
        file.close();
    }

    return ;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    // textStream("C:/Users/Administrator/Desktop/File/readme.txt");
    dataStream("C:/Users/Administrator/Desktop/File/readme.txt");

    return a.exec();
}

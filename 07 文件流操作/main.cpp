#include <QtCore/QCoreApplication>
#include <QFile>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QFile file("C:/Users/Administrator/Desktop/File/readme.txt");
    if( file.open(QIODevice::WriteOnly) ) {
        QString dt = "D.T.Software";
        double dvalue = 3.14;
        file.write(dt.toStdString().c_str());
        file.write(reinterpret_cast<char*>(&dvalue), sizeof(dvalue));
        file.close();
    }

    if(file.open(QIODevice::ReadOnly)) {
        QString dt = QString(file.read(12)) ;
        qDebug() << "dt: " << dt;
        double dvalue;
        file.read(reinterpret_cast<char*>(&dvalue) , sizeof(dvalue));
        qDebug() << "dvalue: " << dvalue;
        file.close();
    }

    return a.exec();
}

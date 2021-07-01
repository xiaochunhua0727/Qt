#include <QtCore/QCoreApplication>
#include <QTemporaryFile>
#include <QDebug>
#include <QFileInfo>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    // 1. ���ļ���д������
    QTemporaryFile tempFile;
    if( tempFile.open() ) {
        tempFile.write("D.T.Software\n");
        tempFile.write("Qt Designer");
    }
    tempFile.close();

    // ��ȡ
    if(tempFile.open()) {
        QString lineText;
        while(!tempFile.atEnd()) {
            lineText = tempFile.readLine();
            qDebug() << "LineText: " << lineText;
        }
    }
    tempFile.close();

    QFileInfo fileAttribute(tempFile);
    qDebug() << "size: " << fileAttribute.size();

    return a.exec();
}

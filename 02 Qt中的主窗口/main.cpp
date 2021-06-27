#include <QtGui/QApplication>
#include "Mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow* w = MainWindow::NewInstance();
    w->show();
    
    return a.exec();
}

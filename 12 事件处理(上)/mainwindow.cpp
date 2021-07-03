#include "mainwindow.h"
#include <QEvent>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

}

void MainWindow::closeEvent(QCloseEvent *event)
{
    qDebug() << "closeEvent(QCloseEvent*)...";
    event->accept();
}

MainWindow::~MainWindow()
{
    
}

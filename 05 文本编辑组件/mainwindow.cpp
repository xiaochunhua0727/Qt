#include "mainwindow.h"
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(600, 420);
    QTextEdit* mainEdit =  new QTextEdit(this);
    mainEdit->move(20, 20);
    mainEdit->resize(550, 380);
    mainEdit->insertPlainText("hell world.\n");
    mainEdit->insertHtml("<img src=\"C:/Users/Administrator/Desktop/kobe.jfif\" />");
}

MainWindow::~MainWindow()
{
    
}

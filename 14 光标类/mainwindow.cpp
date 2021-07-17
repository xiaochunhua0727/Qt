#include "mainwindow.h"
#include <QTextCursor>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_textEdit.setParent(this);
    setCentralWidget(&m_textEdit);
    m_textEdit.setPlainText("Hello world...");
    // 获得当前文本框的光标
    QTextCursor editCursor = m_textEdit.textCursor();
    // 设置光标位置
    editCursor.setPosition(0);
    // 光标位置到指定位置高亮(注: 高亮位置为0-5)
    editCursor.setPosition(5,QTextCursor::KeepAnchor);
    m_textEdit.setTextCursor(editCursor);

    return ;
}

MainWindow::~MainWindow()
{
    
}

#include "mainwindow.h"
#include <QTextCursor>
#include <QPalette>

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

    // note: 失去焦点后，高亮的文本将会变成灰色。因此，需如下设置:
    // 设置文本框的调色板
    QPalette p = m_textEdit.palette();
    // 文本框的文本框颜色(即,背景颜色)
    p.setColor(QPalette::Inactive, QPalette::Highlight, \
                 p.color(QPalette::Active,QPalette::Highlight));
    // QPalette::HighlightedText: 文本框中的文本
    p.setColor(QPalette::Inactive, QPalette::HighlightedText, \
                 p.color(QPalette::Active,QPalette::HighlightedText));
    m_textEdit.setPalette(p);

    return ;
}

MainWindow::~MainWindow()
{
    
}

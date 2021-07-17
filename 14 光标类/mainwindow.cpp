#include "mainwindow.h"
#include <QTextCursor>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_textEdit.setParent(this);
    setCentralWidget(&m_textEdit);
    m_textEdit.setPlainText("Hello world...");
    // ��õ�ǰ�ı���Ĺ��
    QTextCursor editCursor = m_textEdit.textCursor();
    // ���ù��λ��
    editCursor.setPosition(0);
    // ���λ�õ�ָ��λ�ø���(ע: ����λ��Ϊ0-5)
    editCursor.setPosition(5,QTextCursor::KeepAnchor);
    m_textEdit.setTextCursor(editCursor);

    return ;
}

MainWindow::~MainWindow()
{
    
}

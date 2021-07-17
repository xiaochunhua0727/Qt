#include "mainwindow.h"
#include <QTextCursor>
#include <QPalette>

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

    // note: ʧȥ����󣬸������ı������ɻ�ɫ����ˣ�����������:
    // �����ı���ĵ�ɫ��
    QPalette p = m_textEdit.palette();
    // �ı�����ı�����ɫ(��,������ɫ)
    p.setColor(QPalette::Inactive, QPalette::Highlight, \
                 p.color(QPalette::Active,QPalette::Highlight));
    // QPalette::HighlightedText: �ı����е��ı�
    p.setColor(QPalette::Inactive, QPalette::HighlightedText, \
                 p.color(QPalette::Active,QPalette::HighlightedText));
    m_textEdit.setPalette(p);

    return ;
}

MainWindow::~MainWindow()
{
    
}

#include "Widget.h"
#include <QPlainTextEdit>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    m_tabWidget.setParent(this);
    // 控制页切换符显示的位置
    m_tabWidget.setTabPosition(QTabWidget::North);
    // 设置页切换位置的外边框图像
    m_tabWidget.setTabShape(QTabWidget::Triangular);
    // 设置显示页关闭
    m_tabWidget.setTabsClosable(true);

    QPlainTextEdit* textEdit1 = new QPlainTextEdit();
    textEdit1->setPlainText("1st Tab Page.");
    m_tabWidget.addTab(textEdit1, "1St");
    QPlainTextEdit* textEdit2 = new QPlainTextEdit();
    textEdit2->setPlainText("2st Tab Page.");
    m_tabWidget.addTab(textEdit2, "2St");

    connect( &m_tabWidget, SIGNAL(currentChanged(int)), this, SLOT(onTabCurrentChanged(int)) );
    connect(&m_tabWidget, SIGNAL(tabCloseRequested(int)), this, SLOT(onTabCloseRequested(int)) );

    return ;
}

void Widget::onTabCurrentChanged(int index)
{
    qDebug() << "index: " << index;

    return ;
}

void Widget::onTabCloseRequested(int index)
{
    m_tabWidget.removeTab(index);

    return ;
}

Widget::~Widget()
{

}


#include "Widget.h"
#include <QDir>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    m_treeView.setParent(this);
    m_treeView.move(10,10);
    m_treeView.resize(800,300);
    // 为模型设置数据
    m_fsModel.setRootPath(QDir::currentPath());
    // 视图关联到模型
    m_treeView.setModel(&m_fsModel);
    // 利用索引访问模型数据，并在视图中显示
    m_treeView.setRootIndex(m_fsModel.index(QDir::currentPath()));
    return ;
}

Widget::~Widget()
{
}


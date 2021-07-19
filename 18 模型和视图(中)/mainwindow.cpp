#include "mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_edit.setParent(this);
    m_edit.move(10, 10);
    m_edit.resize(500, 300);

    connect( &m_fsm, SIGNAL(directoryLoaded(const QString&)), \
                     this, SLOT(onDirectoryLoad(const QString&)) );
    // 设置模型管理的根路径
    m_fsm.setRootPath(QDir::currentPath());

    return ;
}

void MainWindow::onDirectoryLoad(const QString& path)
{
    QModelIndex root = m_fsm.index(path);
    // 获取索引对应的模型
    // root.model();
    qDebug() << root.data().toString();
    for (int cnt = 0; cnt < m_fsm.rowCount(root); ++cnt) {
        // 依据(row、column、parent)三元素组获取莫
        QModelIndex ci = m_fsm.index(cnt, 1, root);
        qDebug() << ci.data().toString();
    }

    return;
}

MainWindow::~MainWindow()
{

}



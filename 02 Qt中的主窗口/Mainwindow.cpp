#include "Mainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QKeySequence>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
}

MainWindow* MainWindow::NewInstance()
{
    MainWindow* ret = new MainWindow();
    if( (ret == NULL) || !ret->construct()) {
        delete ret;
        ret = NULL;
    }

    return ret;
}

bool MainWindow::construct()
{
    bool ret = true;
    ret = ret && initMenueBar();

    return ret;
}

bool MainWindow::initMenueBar()
{
    bool ret = true;
    QMenuBar* mb = menuBar();
    ret = ret && initFileMenue(mb);

    return ret;
}

bool MainWindow::initFileMenue(QMenuBar* mb)
{
    // 快捷键为Alt + F
    QMenu* menue = new QMenu("File(&F)");
    // 将action添加到Menu中
    bool ret = (menue != NULL);
    if(ret) {
        QAction* action = NULL;
        // 设置快捷键为Ctrl + N
        ret = ret && makeAction(action, "New(N)", Qt::CTRL + Qt::Key_N);
        if(ret) {
            menue->addAction(action);
        }

        menue->addSeparator();
        ret = ret && makeAction(action, "Exit(X)", Qt::CTRL + Qt::Key_X);
        if(ret) {
            menue->addAction(action);
        }
    }

    if(ret) {
        mb->addMenu(menue);
    }

    return ret;
}

bool MainWindow::makeAction(QAction*& action,QString text,int key)
{
    bool ret = true;
    action = new QAction(text, NULL);
    if(action != NULL) {
        action->setShortcut(QKeySequence(key));
    }else {
        ret = false;
    }

    return ret;
}

#include "Mainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QKeySequence>
#include <QToolBar>
#include <QStatusBar>
#include <QLabel>

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
    ret = ret && initToolBar();
    ret = ret && initStatusBar();

    return ret;
}

bool MainWindow::initStatusBar()
{
    bool ret = false;
    QStatusBar* sb = statusBar();
    QLabel* label = new QLabel("D.T.Software");
    if( label ) {
        label->setMinimumWidth(200);
        label->setAlignment(Qt::AlignCenter);
        sb->addPermanentWidget(label);
        ret = true;
    }

    return ret;
}

bool MainWindow::initToolBar()
{
    bool ret = true;
    QToolBar* tb = addToolBar("Tool Bar");
    tb->setIconSize(QSize(16,16));
    ret = ret && initFileToolItem(tb);

    return ret;
}

bool MainWindow::initFileToolItem(QToolBar* tb)
{
    bool ret = true;
    QAction* action = NULL;

    ret = ret && makeAction(action,"New",":/pic/new.png");
    if(ret) {
        tb->addAction(action);
    }

    tb->addSeparator();

    ret = ret && makeAction(action,"Open", ":/pic/open.png");
    if( ret ) {
        tb->addAction(action);
    }

    return ret;
}

bool MainWindow::makeAction(QAction*& action, QString tip, QString icon)
{
    bool ret = false;
    action = new QAction("", NULL);
    if(action != NULL) {
        ret = true;
        action->setToolTip(tip);
        action->setIcon(QIcon(icon));
    }

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

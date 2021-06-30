#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QMenuBar>

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
private:
    MainWindow(QWidget *parent = 0);
    bool construct();
    bool initMenueBar();
    bool initToolBar();
    bool initStatusBar();
    bool initFileToolItem(QToolBar* tb);
    bool makeAction(QAction*& action, QString tip, QString icon);
    bool initFileMenue(QMenuBar* mb);
    bool makeAction(QAction*& action,QString text,int key);
public:
    static MainWindow* NewInstance();
};

#endif // MAINWINDOW_H

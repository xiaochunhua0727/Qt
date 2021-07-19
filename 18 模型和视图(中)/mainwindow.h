#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPlainTextEdit>
#include <QFileSystemModel>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    QPlainTextEdit m_edit;
    QFileSystemModel m_fsm;
protected slots:
    void onDirectoryLoad(const QString& path);
};

#endif // MAINWINDOW_H

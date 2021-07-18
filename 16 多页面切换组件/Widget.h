#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTabWidget>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private slots:
    void onTabCurrentChanged(int);
    void onTabCloseRequested(int);
private:
    QTabWidget m_tabWidget;
};

#endif // WIDGET_H

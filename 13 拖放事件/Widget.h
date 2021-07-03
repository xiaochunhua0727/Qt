#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui/QWidget>
#include <QPlainTextEdit>

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    Widget(QWidget *parent = 0);
    ~Widget();
    void dragEnterEvent(QDragEnterEvent* e);
    void dropEvent(QDropEvent* e);
private:
    QPlainTextEdit mainText;
};

#endif // WIDGET_H

#include "Widget.h"
#include <QList>
#include <QUrl>
#include <QDebug>
#include <QFile>
#include <QIODevice>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
   mainText.setParent(this);
   mainText.move(20,20);
   mainText.resize(600,420);
   setAcceptDrops(true);

   return ;
}

/* 功能: 接受拖事件*/
void Widget::dragEnterEvent(QDragEnterEvent* e)
{
    if( e->mimeData()->hasUrls() ) {
        e->acceptProposedAction();
    }else {
        e->ignore();
    }
}

/* 功能: 接受放事件*/
void Widget::dropEvent(QDropEvent* e)
{
    if( e->mimeData()->hasUrls() ) {
        QList<QUrl> list = e->mimeData()->urls();
        for(int cnt = 0; cnt < list.count(); ++cnt) {
            QString path = list[cnt].toLocalFile();
            qDebug() << "path: " << path;
            mainText.clear();
            QFile file(path);
            if( file.open(QIODevice::ReadOnly)) {
                mainText.appendPlainText(file.readAll());
                file.close();
            }

        }
    }
}

Widget::~Widget()
{
    
}

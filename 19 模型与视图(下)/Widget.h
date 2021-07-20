#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTableView>
#include <QListView>
#include <QTreeView>
#include <QStandardItemModel>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private:
    void initModel();
    void initView();
private:
    QStandardItemModel m_model;
    QTableView m_tableView;
    QListView m_listView;
    QTreeView m_treeView;
};
#endif // WIDGET_H

#include <QtCore/QCoreApplication>
#include <QFileInfo>
#include <QDir>
#include <QDebug>
#include <QFileSystemWatcher>

class Watcher
{
    Q_OBJECT

public:
    Watcher() {
        QObject::connect(&m_watcher, SIGNAL(fileChanged(const QString&)), this, SLOT(statusChanged(const QString&)) );
    }

    void addPath(const QString& path) {
        m_watcher.addPath(path);
    }
private slots:
    void statusChanged(const QString& path) {
        Q_UNUSED(path);
        qDebug() << "file changed...";
    }
private:
    QFileSystemWatcher m_watcher;
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Watcher watcher;
    watcher.addPath("C:/Users/Administrator/Desktop/LeetCode");

    return a.exec();
}

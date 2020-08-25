#include "scanner.h"

Scanner::Scanner(QObject *parent) : QObject(parent)
{
    m_count = 0;
    m_path = "";
}

void Scanner::run()
{
    //We should be on the thread pool

    emit started();

    m_count = 0;
    performScan(m_path);

    emit finished(m_count);
}

QString Scanner::path() const
{
    return m_path;
}

void Scanner::setPath(const QString &path)
{
    m_path = path;
}

void Scanner::performScan(QString path)
{
    //qInfo() << "performScan" << QThread::currentThread();
    m_count++;
    emit updated(m_count);

    QDir dir(path);
    if(!dir.exists()) return;

     QFileInfoList list = dir.entryInfoList(QDir::NoDotAndDotDot | QDir::Dirs);

     foreach(QFileInfo item,list)
     {
           performScan(item.filePath());
     }
}

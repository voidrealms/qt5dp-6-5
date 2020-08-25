#include "filescanner.h"

FileScanner::FileScanner(QObject *parent) : QObject(parent)
{
    //Use a timer to slow down the update process so we dont flood a GUI with changes

    //Updating the GUI is slow and we want the application to remain responsive!
    m_timer.setInterval(500);
    connect(&m_timer,&QTimer::timeout, this, &FileScanner::timeout);
}

void FileScanner::scan(QString path)
{
    m_count = 0;
    m_timer.start();

    Scanner *scanner = new Scanner(nullptr);
    scanner->setAutoDelete(true);
    scanner->setPath(path);

    //Qt::QueuedConnection because these are across threads
    connect(scanner,&Scanner::started,this,&FileScanner::started, Qt::QueuedConnection);
    connect(scanner,&Scanner::updated,this,&FileScanner::updated, Qt::QueuedConnection);
    connect(scanner,&Scanner::finished,this,&FileScanner::finished, Qt::QueuedConnection);

    QThreadPool::globalInstance()->start(scanner);
}

void FileScanner::started()
{
    emit scanStarted();
}

void FileScanner::updated(int value)
{
    m_count = value;
}

void FileScanner::finished(int value)
{
    m_timer.stop();
    emit scanFinished(value);
}

void FileScanner::timeout()
{
    emit scanUpdated(m_count);
}

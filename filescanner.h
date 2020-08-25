#ifndef FILESCANNER_H
#define FILESCANNER_H

#include <QObject>
#include <QDebug>
#include <QFileInfo>
#include <QDir>
#include <QThread>
#include <QThreadPool>
#include <QTimer>
#include "scanner.h"

class FileScanner : public QObject
{
    Q_OBJECT
public:
    explicit FileScanner(QObject *parent = nullptr);

    void scan(QString path);

signals:
    void scanStarted();
    void scanUpdated(int value);
    void scanFinished(int value);

private slots:
    void started();
    void updated(int value);
    void finished(int value);
    void timeout();


private:
    QTimer m_timer;
    int m_count;

};

#endif // FILESCANNER_H

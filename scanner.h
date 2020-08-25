#ifndef SCANNER_H
#define SCANNER_H

#include <QObject>
#include <QRunnable>
#include <QDebug>
#include <QThread>
#include <QFileInfo>
#include <QFileInfoList>
#include <QDir>

class Scanner : public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit Scanner(QObject *parent = nullptr);
    void run() override;

    QString path() const;
    void setPath(const QString &path);

signals:
    void started();
    void updated(int value);
    void finished(int value);

private:
    QString m_path;
    int m_count;
    void performScan(QString path);

};

#endif // SCANNER_H

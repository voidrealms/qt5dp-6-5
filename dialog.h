#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QDir>
#include <QThread>
#include "filescanner.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_btnCount_clicked();
    void scanStarted();
    void scanUpdated(int value);
    void scanFinished(int value);

private:
    Ui::Dialog *ui;
    FileScanner filescanner;
};
#endif // DIALOG_H

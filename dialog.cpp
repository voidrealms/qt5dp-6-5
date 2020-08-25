#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    connect(&filescanner, &FileScanner::scanStarted,this,&Dialog::scanStarted, Qt::QueuedConnection);
    connect(&filescanner, &FileScanner::scanUpdated,this,&Dialog::scanUpdated, Qt::QueuedConnection);
    connect(&filescanner, &FileScanner::scanFinished,this,&Dialog::scanFinished, Qt::QueuedConnection);
    ui->txtPath->setText(QDir::currentPath());
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_btnCount_clicked()
{
    ui->btnCount->setEnabled(false);
    filescanner.scan(ui->txtPath->text());
}

void Dialog::scanStarted()
{
    ui->btnCount->setEnabled(false);
}

void Dialog::scanUpdated(int value)
{
    ui->lblStatus->setText("Counting:" + QString::number(value));
}

void Dialog::scanFinished(int value)
{
    ui->btnCount->setEnabled(true);
    ui->lblStatus->setText("Total:" + QString::number(value));
}

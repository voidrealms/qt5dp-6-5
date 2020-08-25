#include "dialog.h"

#include <QApplication>

/*

  What
  Modify the FileScanner class and show in Widgets

  Description
  Show how to update the GUI (Widgets) from a Thread

  Why
  We can not lock the Main thread

  Example
  Count folders via threads and update the GUI

 */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.show();
    return a.exec();
}

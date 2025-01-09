#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Auto Clicker");
    w.setWindowIcon(QIcon(":/applicationIcon.ico"));
    w.show();
    return a.exec();
}

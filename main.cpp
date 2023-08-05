#include "mainwindow.h"

#include <QApplication>
#include <QScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QRect screenRect = a.primaryScreen()->geometry();
    w.move(screenRect.center().x() - w.geometry().center().x(), screenRect.center().y() - w.geometry().center().y());
    w.show();
    return a.exec();
}

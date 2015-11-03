#include <QApplication>
#include "mywidget.h"
#include <QDesktopWidget>
#include <QSurfaceFormat>

#include "mainwindow.h"
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MyWidget mywidget;
    mywidget.show();
    return app.exec();
}

#include <QApplication>
#include <GLUT/GLUT.h>
#include "mywidget.h"
#include <QDesktopWidget>
#include <QSurfaceFormat>

#include "mainwindow.h"
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    QApplication app(argc, argv);
    MyWidget mywidget;
    mywidget.show();
    return app.exec();
}

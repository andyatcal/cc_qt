#include <QApplication>
#include <GL/glut.h>
#include <GL/gl.h>
#include "mywidget.h"
#include <QDesktopWidget>
#include <QSurfaceFormat>
#include <iostream>

#include "mainwindow.h"
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    QApplication app(argc, argv);
    MyWidget mywidget;
    mywidget.show();
    return app.exec();
}

#if __linux__
 #include <GL/glut.h>
 #include <GL/gl.h>
#elif __APPLE__
 #include <GLUT/GLUT.h>
#endif

#include <QApplication>
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

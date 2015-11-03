#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QSlider;
class QPushButton;
QT_END_NAMESPACE

class GLWidget;

class MyWidget : public QWidget
{


public:
    MyWidget();
    ~MyWidget();
    GLWidget * myGLWidget;
    QSlider * brSlider;
    QSlider * bgSlider;
    QSlider * bbSlider;
    QSlider * CCLevel;
    QSlider * dxSlider;
    QSlider * dySlider;
    QSlider * dzSlider;
    QSlider * levelSlider;
    QSlider * offsetSlider;
};

#endif // MYWIDGET_H

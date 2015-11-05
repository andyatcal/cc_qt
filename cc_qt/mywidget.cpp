#if __linux__
 #include <QVBoxLayout>
 #include <QHBoxLayout>
#elif __APPLE__
 #include <QVBOXLAYOUT>
 #include <QHBOXLAYOUT>
#endif

#include "mywidget.h"
#include <QSlider>
#include <QLabel>
#include <QButtonGroup>
#include <QRadioButton>
#include <QtDebug>
#include "myglwidget.h"

MyWidget::MyWidget()
{
    QVBoxLayout * mainLayout;
    setLayout(mainLayout = new QVBoxLayout);
    QVBoxLayout * controlsLayout;
    mainLayout -> addLayout(controlsLayout = new QVBoxLayout);
    mainLayout -> addWidget(myGLWidget = new GLWidget);
    QHBoxLayout * BGLayout;
    controlsLayout -> addLayout(BGLayout = new QHBoxLayout);
    BGLayout -> addWidget(new QLabel("Background Color: "));
    BGLayout -> addWidget(new QLabel("Red"));
    BGLayout -> addWidget(brSlider = new QSlider(Qt::Horizontal));
    BGLayout -> addWidget(new QLabel("Green"));
    BGLayout -> addWidget(bgSlider = new QSlider(Qt::Horizontal));
    BGLayout -> addWidget(new QLabel("Blue"));
    BGLayout -> addWidget(bbSlider = new QSlider(Qt::Horizontal));
    brSlider -> setMinimum(0);
    brSlider -> setMaximum(256);
    brSlider -> setValue(256);
    bgSlider -> setMinimum(0);
    bgSlider -> setMaximum(256);
    bgSlider -> setValue(256);
    bbSlider -> setMinimum(0);
    bbSlider -> setMaximum(256);
    bbSlider -> setValue(256);
    connect(brSlider, SIGNAL(valueChanged(int)), myGLWidget, SLOT(setBGR(int)));
    connect(bgSlider, SIGNAL(valueChanged(int)), myGLWidget, SLOT(setBGG(int)));
    connect(bbSlider, SIGNAL(valueChanged(int)), myGLWidget, SLOT(setBGB(int)));
    QHBoxLayout * cubeDimensionLayout;
    controlsLayout -> addLayout(cubeDimensionLayout = new QHBoxLayout);
    cubeDimensionLayout -> addWidget(new QLabel("Cube Dimensions: "));
    cubeDimensionLayout -> addWidget(new QLabel("Length "));
    cubeDimensionLayout -> addWidget(dxSlider = new QSlider(Qt::Horizontal));
    cubeDimensionLayout -> addWidget(new QLabel("Width "));
    cubeDimensionLayout -> addWidget(dySlider = new QSlider(Qt::Horizontal));
    cubeDimensionLayout -> addWidget(new QLabel("Height "));
    cubeDimensionLayout -> addWidget(dzSlider = new QSlider(Qt::Horizontal));
    dxSlider -> setMinimum(5);
    dxSlider -> setMaximum(15);
    dySlider -> setMinimum(5);
    dySlider -> setMaximum(15);
    dzSlider -> setMinimum(5);
    dzSlider -> setMaximum(15);
    connect(dxSlider, SIGNAL(valueChanged(int)), myGLWidget, SLOT(setCubeX(int)));
    connect(dySlider, SIGNAL(valueChanged(int)), myGLWidget, SLOT(setCubeY(int)));
    connect(dzSlider, SIGNAL(valueChanged(int)), myGLWidget, SLOT(setCubeZ(int)));
    QHBoxLayout * subdivisionLayout;
    controlsLayout -> addLayout(subdivisionLayout = new QHBoxLayout);
    subdivisionLayout -> addWidget(new QLabel("Subdivision Level"));
    subdivisionLayout -> addWidget(levelSlider = new QSlider(Qt::Horizontal));
    levelSlider -> setMinimum(0);
    levelSlider -> setMaximum(5);
    connect(levelSlider, SIGNAL(valueChanged(int)), myGLWidget, SLOT(setLevel(int)));
    QHBoxLayout * selectionLayout;
    controlsLayout -> addLayout(selectionLayout = new QHBoxLayout);
    QButtonGroup * isWireFrame = new QButtonGroup();
    QRadioButton * wireFrame_true;
    QRadioButton * wireFrame_false;
    isWireFrame -> addButton(wireFrame_false = new QRadioButton("Solid "));
    isWireFrame -> addButton(wireFrame_true = new QRadioButton("WireFrame "));
    selectionLayout -> addWidget(wireFrame_false);
    selectionLayout -> addWidget(wireFrame_true);
    wireFrame_false -> setChecked(true);
    connect(wireFrame_false, SIGNAL(clicked(bool)), myGLWidget, SLOT(setWireFrameFalse(bool)));
    connect(wireFrame_true, SIGNAL(clicked(bool)), myGLWidget, SLOT(setWireFrameTrue(bool)));
    QHBoxLayout * offsetLayout;
    controlsLayout -> addLayout(offsetLayout = new QHBoxLayout);
    QButtonGroup * withOffset = new QButtonGroup();
    QRadioButton * withOffset_true;
    QRadioButton * withOffset_false;
    withOffset -> addButton(withOffset_false = new QRadioButton("No Offset "));
    withOffset -> addButton(withOffset_true = new QRadioButton("Offset "));
    offsetLayout -> addWidget(withOffset_false);
    offsetLayout -> addWidget(withOffset_true);
    withOffset_false -> setChecked(true);
    offsetLayout -> addWidget(new QLabel("Offset Value: "));
    offsetLayout -> addWidget(offsetSlider = new QSlider(Qt::Horizontal));
    connect(withOffset_false, SIGNAL(clicked(bool)), myGLWidget, SLOT(setWithOffsetFalse(bool)));
    connect(withOffset_true, SIGNAL(clicked(bool)), myGLWidget, SLOT(setWithOffsetTrue(bool)));
    connect(offsetSlider, SIGNAL(valueChanged(int)), myGLWidget, SLOT(setOffset(int)));
    offsetSlider -> setMinimum(2);
    offsetSlider -> setMaximum(20);
    offsetSlider -> setValue(11);
}

#-------------------------------------------------
#
# Project created by QtCreator 2015-10-12T13:49:51
#
#-------------------------------------------------

QT       += core gui opengl

CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cc_qt
TEMPLATE = app


SOURCES += main.cpp\
    mywidget.cpp \
    myglwidget.cpp \
    logo.cpp

HEADERS  += \
    edge.h \
    face.h \
    mesh.h \
    vertex.h \
    makeMesh.h \
    offset.h \
    stl.h \
    subdivision.h \
    viewport.h \
    merge.h \
    mywidget.h \
    myglwidget.h \
    logo.h

FORMS    +=

mac: INCLUDEPATH = /usr/local/include

mac: LIBS += -framework GLUT -framework OpenGL

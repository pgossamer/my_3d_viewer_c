QT += core gui widgets opengl openglwidgets
include (../QtGifImage/src/gifimage/qtgifimage.pri)

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TARGET = 3DViewer_v1.0
TEMPLATE = app

SOURCES += main.cpp \
    affine_transformations.c \
    mainwindow.cpp \
    parser.c

SOURCES += \
    mainwidget.cpp \
    geometryengine.cpp
    mainwindow.cpp

HEADERS += \
    affine_transformations.h \
    affine_transformations.h \
    mainwidget.h \
    geometryengine.h \
    mainwindow.h \
    parser.h \
    mainwindow.h

RESOURCES += \
    images.qrc \
    shaders.qrc

FORMS += \
    mainwindow.ui

FORMS += \
    mainwindow.ui

DEFINES += HOME_DIR=\\\"$(HOME)\\\"

HEADERS += \
    affine_transformations.h \
    mainwidget.h \
    geometryengine.h \
    mainwindow.h \
    parser.h \
    mainwindow.h

RESOURCES += \
    images.qrc \
    shaders.qrc

FORMS += \
    mainwindow.ui

FORMS += \
    mainwindow.ui

DEFINES += HOME_DIR=\\\"$(HOME)\\\"

macx:ICON = app.icns

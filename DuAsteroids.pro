#-------------------------------------------------
# Author: Carlos Enrique Duarte Ortiz <carlosduarte.1@hotmail.com>
#
# Project created by QtCreator 2014-12-25T18:35:35
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QGraphicsView
TEMPLATE = app

SOURCES += main.cpp \
    DuAsteroidsAbstractShape.cpp \
    DuAsteroidsAsteroid.cpp \
    DuAsteroidsMissile.cpp \
    DuAsteroidsCircleItem.cpp \
    DuAsteroidsLineItem.cpp \
    DuAsteroidsScene.cpp \
    DuAsteroidsTextItem.cpp \
    DuAsteroidsThread.cpp \
    DuAsteroidsStarship.cpp \
    DuAsteroidsText.cpp \
    DuAsteroidsUtil.cpp \
    DuAsteroidsMainWidget.cpp

HEADERS  += \
    DuAsteroidsDefines.h \
    DuAsteroidsAbstractShape.h \
    DuAsteroidsAsteroid.h \
    DuAsteroidsMissile.h \
    DuAsteroidsCircleItem.h \
    DuAsteroidsLineItem.h \
    DuAsteroidsScene.h \
    DuAsteroidsTextItem.h \
    DuAsteroidsThread.h \
    DuAsteroidsStarship.h \
    DuAsteroidsText.h \
    DuAsteroidsUtil.h \
    DuAsteroidsMainWidget.h

FORMS    += \
    DuAsteroidsMainWidget.ui

QMAKE_CXXFLAGS += -std=gnu++14

RESOURCES += \
    res.qrc

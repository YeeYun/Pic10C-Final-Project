#-------------------------------------------------
#
# Project created by QtCreator 2015-05-25T12:12:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = game1
TEMPLATE = app
QMAKE_MAC_SDK = macosx10.9

SOURCES += main.cpp \
    MyRect.cpp \
    MyBullet.cpp \
    MyEnemy.cpp \
    MyScore.cpp \
    Game.cpp \
    MyHealth.cpp

HEADERS  += \
    MyRect.h \
    MyBullet.h \
    MyEnemy.h \
    MyScore.h \
    Game.h \
    MyHealth.h

FORMS    +=

RESOURCES += \
    MyResources.qrc

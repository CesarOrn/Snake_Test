#-------------------------------------------------
#
# Project created by QtCreator 2016-05-17T10:55:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Snake
TEMPLATE = app


SOURCES += main.cpp \
    Body.cpp \
    Board.cpp

HEADERS  += \
    Body.h \
    Board.h

FORMS    += mainwindow.ui

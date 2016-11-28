#-------------------------------------------------
#
# Project created by QtCreator 2016-11-25T01:32:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    wiringpi.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

LIBS += -lwiringPi\
        -lpthread
CONFIG += c++11

#-------------------------------------------------
#
# Project created by QtCreator 2015-08-20T12:45:13
#
#-------------------------------------------------

QT       += core gui network testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ServerExample
TEMPLATE = app

INCLUDEPATH += ../lib\
               ../lib/Server\
               ../lib/Config

LIBS += ../bin/Server.dll

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

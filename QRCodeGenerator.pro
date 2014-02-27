QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = "QRCode Generator"
TEMPLATE = app

DESTDIR = ../bin

SOURCES += main.cpp\
    QRCodeGenerator.cpp \
    mainwindow.cpp

HEADERS  += \
    QRCodeGenerator.h \
    mainwindow.h

FORMS    += \
    mainwindow.ui

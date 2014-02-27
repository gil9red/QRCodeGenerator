QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = "QRCode Generator"
TEMPLATE = app

DESTDIR = ../bin

SOURCES += main.cpp\
        Widget.cpp \
    QRCodeGenerator.cpp

HEADERS  += Widget.h \
    QRCodeGenerator.h

FORMS    += Widget.ui

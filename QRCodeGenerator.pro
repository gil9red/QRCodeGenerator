QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QRCodeGenerator
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

BINDIR  = $$PREFIX/bin
DATADIR = $$PREFIX/share
target.path = $$BINDIR
desktop.files = QRCodeGenerator.desktop
desktop.path = $$DATADIR/applications/
icon.files = QRCodeGenerator.png
icon.path= $$DATADIR/icons/
INSTALLS += target desktop icon

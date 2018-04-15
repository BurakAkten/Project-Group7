QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = proje_gui_windows
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

HEADERS += \
    mainwindow.h \
    bolgeekle.h \
    secondwindow.h

SOURCES += \
    mainwindow.cpp \
    secondwindow.cpp \
    bolgeekle.cpp \
    main.cpp

FORMS += \
    bolgeekle.ui \
    mainwindow.ui \
    secondwindow.ui

RESOURCES += \
    resources.qrc

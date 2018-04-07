#-------------------------------------------------
#
# Project created by QtCreator 2018-03-31T21:24:45
#
#-------------------------------------------------

QT       += core gui
QT += multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = proje_gui
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += \
        c++11 \
        link_pkgconfig

PKGCONFIG += opencv

LIBS += -L/home/furkan/Desktop/opencv-3.4.1/build/lib \         # buraya opencv kütüphanesi path 'i verilmeli

SOURCES += \
        main.cpp \
    secondwindow.cpp \
    mainwindow.cpp \
    bolgeekle.cpp \
    Client/Client.cpp \
    Client/MatConverter.cpp \
    Client/Networkable.cpp \
    Client/runClient.cpp  \
    Client/supporting/restart.c \
    Client/supporting/uici.c \
    Client/supporting/uiciname.c


HEADERS += \
    secondwindow.h \
    mainwindow.h \
    bolgeekle.h \
    Client/Client.h \
    Client/MatConverter.h \
    Client/Networkable.h \
    Client/supporting/restart.h \
    Client/supporting/uici.h \
    Client/supporting/uiciname.h

FORMS += \
    secondwindow.ui \
    mainwindow.ui \
    bolgeekle.ui

RESOURCES += \
    recources.qrc
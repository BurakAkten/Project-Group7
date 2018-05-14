#-------------------------------------------------
#
# Project created by QtCreator 2018-03-31T21:24:45
#
#-------------------------------------------------

QT += core gui
QT += multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = proje_gui
TEMPLATE = app
INCLUDEPATH += .

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

LIBS += -L/usr/lib -lmysqlcppconn \

SOURCES += \
    main.cpp \
    secondwindow.cpp \
    mainwindow.cpp \
    Client/Client.cpp \
    Client/MatConverter.cpp \
    Client/Networkable.cpp \
    Client/supporting/restart.c \
    Client/supporting/uici.c \
    Client/supporting/uiciname.c \
    qcustomplot.cpp \
    rapor.cpp \
    Client/supporting/wrestart.cpp \
    graphs.cpp \
    bolgeekle.cpp \
    dbconnection.cpp

HEADERS += \
    secondwindow.h \
    mainwindow.h \
    Client/Client.h \
    Client/MatConverter.h \
    Client/Networkable.h \
    Client/supporting/restart.h \
    Client/supporting/uici.h \
    Client/supporting/uiciname.h \
    qcustomplot.h \
    rapor.h \
    Client/supporting/wrestart.h \
    graphs.h \
    bolgeekle.h \
    dbconnection.h \
    region.h

FORMS += \
    secondwindow.ui \
    mainwindow.ui \
    graphs.ui \
    bolgeekle.ui

RESOURCES += \
    recources.qrc

QT += core gui sql
QT += multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = proje_gui
TEMPLATE = app
INCLUDEPATH += .

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += staticlib qt c++11

LIBS += ${OpenCV_LIBS}

INCLUDEPATH += ${OpenCV_INCLUDE_DIRS}

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
    dbconnection.cpp \
    editregion.cpp \
    detectedimage.cpp

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
    region.h \
    editregion.h \
    Client/Command.h \
    detectedimage.h

FORMS += \
    secondwindow.ui \
    mainwindow.ui \
    graphs.ui \
    bolgeekle.ui \
    editregion.ui \
    detectedimage.ui

RESOURCES += \
    recources.qrc

DISTFILES += \
    Client/libws2_32.a

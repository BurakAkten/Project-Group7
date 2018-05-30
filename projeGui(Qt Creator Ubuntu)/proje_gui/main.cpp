#include "mainwindow.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow w;
    w.setWindowTitle("Ana Ekran");
    w.show();

    //SecondWindow s;

    return app.exec();
}

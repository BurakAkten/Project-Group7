#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    SecondWindow s;
    if(w.isActiveWindow() == true)
        s.show();

    return a.exec();
}

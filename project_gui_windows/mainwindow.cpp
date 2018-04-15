#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
        ui->setupUi(this);
        QPixmap pix(":/Resources/images/gtu.png");
        int w = ui->gtu->width();
        int h = ui->gtu->height();
        ui->gtu->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));

        QPixmap pix2(":/Resources/images/dikkat.png");
        w = ui->dikkat->width();
        h = ui->dikkat->height();
        ui->dikkat->setPixmap(pix2.scaled(w, h, Qt::KeepAspectRatio));
    }

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_pushButton_clicked() {
    this->close();
    secWindow = new SecondWindow(this);
    secWindow->show();
}


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QImage image(":/Resources/images/gtu.png");
    ui->gtu->setPixmap(QPixmap::fromImage(image));
    ui->gtu->setScaledContents(true);
    ui->gtu->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    QImage image2(":/Resources/images/dikkat.png");
    ui->dikkat->setPixmap(QPixmap::fromImage(image2));
    ui->dikkat->setScaledContents(true);
    ui->dikkat->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    //this->hide();
    this->close();
    secWindow = new SecondWindow(this);
    secWindow->show();

}


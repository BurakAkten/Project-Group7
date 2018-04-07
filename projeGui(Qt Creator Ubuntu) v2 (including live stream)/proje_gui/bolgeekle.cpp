#include "bolgeekle.h"
#include "ui_bolgeekle.h"

#include <string>
#include <iostream>

#include "QMessageBox"
#include "QString"
#include "QDebug"

using namespace std;

BolgeEkle::BolgeEkle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BolgeEkle)
{
    ui->setupUi(this);
}

BolgeEkle::~BolgeEkle()
{
    delete ui;
}

void BolgeEkle::on_pushButton_clicked()
{
    // QString line = ui->lineEdit->text();
    //  QDebug.noquote() << line;
    //QMessageBox::information(this,"title",line);
    close();
}

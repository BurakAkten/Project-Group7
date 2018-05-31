#include "editregion.h"
#include "ui_editregion.h"

EditRegion::EditRegion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditRegion)
{
    ui->setupUi(this);
}

EditRegion::EditRegion(QWidget *parent, Region* region) :
    QDialog(parent),
    ui(new Ui::EditRegion)
{
    ui->setupUi(this);
    this->region = region;


    this->setWindowTitle(QString::fromStdString(region->name)+" Düzenleme");
    ui->lineEdit_X1->setValidator(new QDoubleValidator());
    ui->lineEdit_X2->setValidator(new QDoubleValidator());
    ui->lineEdit_Y->setValidator(new QDoubleValidator());

}
EditRegion::~EditRegion()
{
    delete ui;
}

void EditRegion::on_edit_clicked()
{

    QString x1=ui->lineEdit_X1->text(), x2=ui->lineEdit_X2->text(), y= ui->lineEdit_Y->text();

    if(x1.size() ==0 || x2.size() ==0 || y.size()==0){
        ui->label_5->setText("Tüm bilgileri doldurun !!");
        ui->label_5->setStyleSheet("QLabel { color : red; }");
        ui->label_5->setAlignment(Qt::AlignCenter);
    }
    else
    {
        region->x1 = x1.trimmed().replace(",",".").toDouble();
        region->x2 = x2.trimmed().replace(",",".").toDouble();
        region->y  =  y.trimmed().replace(",",".").toDouble();
        close();
    }

}

#include "bolgeekle.h"
#include "ui_bolgeekle.h"

#include <QFile>
#include <QString>
#include <QTextStream>


BolgeEkle::BolgeEkle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BolgeEkle)
{
    ui->setupUi(this);

}
BolgeEkle::BolgeEkle(QWidget *parent, QListWidget* list) :
    QDialog(parent),
    ui(new Ui::BolgeEkle)
{
    ui->setupUi(this);
    this->listWidget = list;

    ui->lineEdit_X->setValidator(new QDoubleValidator());
    ui->lineEdit_Y->setValidator(new QDoubleValidator());

}

BolgeEkle::~BolgeEkle()
{
    delete ui;
}

void BolgeEkle::on_ekle_clicked()
{
    QTextStream out(stdout);

    QString regionName = ui->lineEdit_Name->text().trimmed();
    QString x=ui->lineEdit_X->text(), y= ui->lineEdit_Y->text();

    if(regionName.size() ==0 || x.size() ==0 || y.size()==0){
        ui->label_5->setText("Tüm bilgileri doldurun !!");
        ui->label_5->setStyleSheet("QLabel { color : red; }");
        ui->label_5->setAlignment(Qt::AlignCenter);
    }
    else
    {
        int listSize = listWidget->count();
        bool found= false;
        for (int i = 0; i < listSize; ++i) {
            QListWidgetItem* item = listWidget->item(i);
            if(item->text() == regionName){     // aynı isimli bölge var mı ?
                found = true;
            }
        }
        if(!found){     // yeni bölge
            QFile file("/home/furkan/Qt Projects/proje_gui/Files/coordinates.csv");
            if (file.open(QIODevice::WriteOnly | QIODevice::Append)) {
                QTextStream stream(&file);
                stream << regionName+";"+x+";"+y << endl;   // dosyaya eklendi

                Region region;
                region.name = regionName.toStdString();
                region.x    = x.toDouble();
                region.y    = y.toDouble();


                QListWidgetItem *item = new QListWidgetItem();
                item->setData(Qt::UserRole, QVariant::fromValue(region));
                item->setText(regionName);
                listWidget->addItem(item);  // listeye eklendi
                close();
            }
            else
            {
                out << "Dosya açılamadı!";
                return;
            }
        }else {
            ui->label_5->setText("Bölge ismi farklı olmalı !!");
            ui->label_5->setStyleSheet("QLabel { color : red; }");
            ui->label_5->setAlignment(Qt::AlignCenter);
        }
    }




}

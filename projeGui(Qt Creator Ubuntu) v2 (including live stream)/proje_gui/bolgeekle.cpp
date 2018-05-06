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
    this->list = list;

}

BolgeEkle::~BolgeEkle()
{
    delete ui;
}

void BolgeEkle::on_ekle_clicked()
{
    QTextStream out(stdout);
    QFile file("/home/furkan/Qt Projects/proje_gui/Files/coordinates.csv");  // :/Resources/Files/   ---- dosya konumu elle verilmeli !!!!!!!!!!!!!
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        out << "File is not opened!!" << endl;
        return;
    }

    QTextStream in(&file);
    in.readLine();              // dosyanın ilk satırı eklenmeyecek ; ilk satır okunmadı


    QVector<QString> lines;
    QStringList tokens;
    while (!in.atEnd()) {
        QRegExp sep(";");
        tokens =  in.readLine().split(sep);
        lines.push_back(tokens.at(0));
    }

    file.flush();
    file.close();

    QString regionName = ui->lineEdit_Name->text().trimmed();

    if(!(std::find(lines.begin(), lines.end(), regionName) != lines.end()))
    {
        QString x=ui->lineEdit_X->text(), y= ui->lineEdit_Y->text();

        QListWidgetItem *item = new QListWidgetItem();
        item->setText(regionName);
        list->addItem(item);
        list->viewport()->repaint();

        QFile file2("/home/furkan/Qt Projects/proje_gui/Files/coordinates.csv");
        if (file2.open(QIODevice::WriteOnly | QIODevice::Append)) {
            QTextStream stream(&file2);
            stream << regionName+";"+x+";"+y << endl;
        }
        else
        {
            out << "qsdas dasd asdasd";
            return;
        }
        file2.close();

        close();
    }
    else{
        ui->label_5->setText("Bölge ismi farklı olmalı !!");
    }



}

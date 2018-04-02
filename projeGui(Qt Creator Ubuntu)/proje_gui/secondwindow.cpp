#include "secondwindow.h"
#include "ui_secondwindow.h"

#include <QFile>
#include <QTextStream>
#include <QString>
#include <QStringList>
#include <QHeaderView>
#include <QTextStream>


SecondWindow::SecondWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SecondWindow)
{
    ui->setupUi(this);


    loadImages();

    ui->tableWidget->setColumnCount(3);
    for(int i = 0; i < 3; i++)
        ui->tableWidget->setColumnWidth(i, 257);

    ui->tableWidget->setHorizontalHeaderLabels(QString("Bölge;Tarih;Görüntü Numarası").split(";"));
    QHeaderView* header = ui->tableWidget->horizontalHeader();
    header->setSectionResizeMode(QHeaderView::Stretch);

    ui->listWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);     // edit engellemek için
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);    // edit engellemek için
    getTableInfo();
    getListInfo();
}

SecondWindow::~SecondWindow()
{
    delete ui;
}



void SecondWindow::on_bolge_ekle_2_clicked()    // bolge ekleme butonu
{
    bolge = new BolgeEkle(this);
    bolge->show();

}

void SecondWindow::on_bolge_sec_2_clicked()
{
    //getTableInfo();

}
void SecondWindow::getListInfo(){

    QTextStream out(stdout);
    QFile file(":/Resources/Files/coordinates.csv");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        out << "File is not opened!!" << endl;
        return;
    }

    QTextStream in(&file);
    in.readLine();              // ilk satır okunmadı
    int lineNumber =0;
    while (!in.atEnd()) {
        in.readLine();
        ++lineNumber;           // satır sayısı bulundu
    }

    in.flush();
    in.reset();
    in.seek(0);


    QListWidget* list = ui->listWidget;
    int listSize = list->sizeHintForColumn(0);

    in.readLine();
    for(int i=0; i< listSize; ++i)
    {
        in.readLine();      // cursor, o anki listenin sonuna geldi
    }


    QString line;
    QStringList tokens;
    for (int i = listSize; i < lineNumber; ++i) {    // satır split edildi ve bölge adı listeye eklendi
        line = in.readLine();
        QRegExp sep(";");
        tokens =  line.split(sep);
        QListWidgetItem *item = new QListWidgetItem();
        item->setText(tokens.at(0));
        list->addItem(item);
    }

    list->viewport()->repaint();
    return;
}

void SecondWindow::getTableInfo(){

    QTextStream out(stdout);
    QFile file(":/Resources/Files/determined.csv");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        out << "File is not opened!!" << endl;
        return;
    }

    QTextStream in(&file);
    in.readLine();              // dosyanın ilk satırı eklenmeyecek ; ilk satır okunmadı
    int lineNumber =0;
    while (!in.atEnd()) {
        in.readLine();
        ++lineNumber;           // satır sayısı bulundu
    }

    in.flush();
    in.reset();
    in.seek(0);


    QTableWidget* table = ui->tableWidget;
    int rowSize = table->rowCount();

    in.readLine();
    for(int i=0; i< rowSize; ++i)
    {
        in.readLine();      // cursor, o anki tablonun son row'una geldi
    }


    QString line;
    QStringList tokens;
    for (int i = rowSize; i < lineNumber; ++i) {    // yeni row eklendi ve yeni itemler tabloya eklendi
        table->insertRow(i);
        line = in.readLine();
        QRegExp sep(";");
        tokens =  line.split(sep);
        for (int j = 0; j < 3; ++j) {   // 3 column var : Bölge;Tarih;Görüntü Numarası
            QTableWidgetItem *item = new QTableWidgetItem();
            //item->setFlags(item->flags() ^ Qt::ItemIsEditable);
            item->setText(tokens.at(j));
            table->setItem   ( i, j, item);
        }
    }

    table->viewport()->repaint();
    return;
}
void SecondWindow::loadImages(){

    QPixmap *image = new QPixmap(":/Resources/images/gtu.png");
    int w = ui->gtu->width();
    int h = ui->gtu->height();
    ui->gtu->setPixmap(image->scaled(w, h, Qt::KeepAspectRatio));

    image = new QPixmap(":/Resources/images/dikkat.png");
    w = ui->dikkat1->width();
    h = ui->dikkat1->height();
    ui->dikkat1->setPixmap(image->scaled(w, h, Qt::KeepAspectRatio));

    w = ui->dikkat2->width();
    h = ui->dikkat2->height();
    ui->dikkat2->setPixmap(image->scaled(w, h, Qt::KeepAspectRatio));

    image = new QPixmap(":/Resources/images/play.png");
    QIcon ButtonIcon(*image);
    ui->play->setIcon(ButtonIcon);
    ui->play->setIconSize(QSize(60,55));

    image = new QPixmap(":/Resources/images/stop.png");
    QIcon ButtonIcon2(*image);
    ui->stop->setIcon(ButtonIcon2);
    ui->stop->setIconSize(QSize(60,55));


    image = new QPixmap(":/Resources/images/fullScreen.png");
    QIcon ButtonIcon3(*image);
    ui->fullScreen->setIcon(ButtonIcon3);
    ui->fullScreen->setIconSize(QSize(60,100));
}


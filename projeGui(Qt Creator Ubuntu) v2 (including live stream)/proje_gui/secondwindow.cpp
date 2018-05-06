#include "secondwindow.h"
#include "ui_secondwindow.h"

#include <QFile>
#include <QTextStream>
#include <QString>
#include <QStringList>
#include <QHeaderView>
#include <QTextStream>

#include <QMessageBox>

#include <QBuffer>
#include <QVideoWidget>
#include <QMediaPlayer>


#include <iostream>
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"

#include "Client/supporting/uici.h"
#include "Client/supporting/restart.h"
#include "Client/MatConverter.h"
#include "Client/Client.h"


#include "QCloseEvent"
#include <functional> // bind

#define WINDOW_NAME "WINDOW"


SecondWindow::SecondWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SecondWindow)
{

    ui->setupUi(this);

    loadImages();

    db.setHostName("bigblue");
    db.setDatabaseName("flightdb");
    db.setUserName("acarlson");
    db.setPassword("1uTbSbAs");
    bool ok = db.open();


    ui->tableWidget->setColumnCount(2);
    for(int i = 0; i < 2; i++)
        ui->tableWidget->setColumnWidth(i, 257);

    ui->tableWidget->setHorizontalHeaderLabels(QString("Bölge;Tarih").split(";"));
    QHeaderView* header = ui->tableWidget->horizontalHeader();
    header->setSectionResizeMode(QHeaderView::Stretch);

    ui->listWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);     // edit engellemek için
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);    // edit engellemek için
    ui->tableWidget->setSortingEnabled(true);
    getTableInfo();
    getListInfo();
}

SecondWindow::~SecondWindow()
{
    delete ui;
}

void SecondWindow::on_bolge_sec_2_clicked()
{
    //RUN THE SYSTEM
}

void SecondWindow::on_bolge_ekle_2_clicked() {
    bolge = new BolgeEkle(this, raports, 1);
    bolge->show();
}

void SecondWindow::on_openDateGraph_clicked() {
    bolge = new BolgeEkle(this, raports, 2);
    bolge->show();
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
    for(int i=0; i< rowSize; ++i) {
        in.readLine();      // cursor, o anki tablonun son row'una geldi
    }

    this->raports.clear();
    QString line;
    QStringList tokens;
    for (int i = rowSize; i < lineNumber; ++i) {    // yeni row eklendi ve yeni itemler tabloya eklendi
        table->insertRow(i);
        line = in.readLine();
        QRegExp sep(";");
        tokens =  line.split(sep);

        Rapor newRapor(i, tokens.at(0).toStdString(), tokens.at(1).toStdString());
        this->raports.push_back(newRapor);
        for (int j = 0; j < 2; ++j) {   // 2 column var : Bölge;Tarih
            QTableWidgetItem *item = new QTableWidgetItem();
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


/*
    Canlı yayın client
*/
void SecondWindow::callback(Client& client) {


    Mat frame;
        Mat decompressedFrame;
        QImage image1;

        bool connectionActive = true;
        for (;connectionActive;) {

            if (client.hasDataPending()) {
                cout << "Data pending " << client.dataPending() << endl;
            }
            else {
                cout << "No data pending" << endl;
            }

            if(client.receive(frame)) {
                err("client.receive()");
                connectionActive = false;
            } else {

                pyrUp(frame, decompressedFrame);

                cvtColor(frame, frame, CV_BGR2RGB);    //  renkleri Qt ye uygun hale getirmek için
                image1= QImage((uchar*) frame.data, frame.cols, frame.rows, frame.step, QImage::Format_RGB888);


                ui->video->setPixmap(QPixmap::fromImage(image1));
                ui->video->setScaledContents( true );
                ui->video->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
                ui->video->show();

                //imshow(WINDOW_NAME, frame);

                if (cv::waitKey(30) >= 0 || stop == true) {
                    client.disconnectFromServer();
                    connectionActive = false;
                }
            }
        }

    image1 = QImage();
    ui->video->setPixmap(QPixmap::fromImage(image1));
    ui->video->show();  // biterken ekranı boşaltmak için*/

   // destroyAllWindows();
}

/*
Play butonuna tıkalndıgında client server'a istek yolluyor
*/
void SecondWindow::on_play_clicked() {
    stop = false;

    auto f = bind(&SecondWindow::callback, this, std::placeholders::_1);


    cout << "- CLIENT STARTED -" << endl;

    const string ipAddress = "10.1.130.243";
    const string localIp = "localhost";

    Client client(localIp, f);
    if (client.connectToServer()) {
        err("client.connect()");
        #if _WIN32
            cout << WSAGetLastError() << endl;
        #endif
        exit(1);
    }

    cout << "- CLIENT EXITED -" << endl;

}


void SecondWindow::on_stop_clicked() {
    stop = true;
    if (isFullScreen == true) {
        this->show();
        ui->frame->setWindowFlags(Qt::Widget);  //    and to go back make it a widget again:
        ui->frame->show();
        isFullScreen = false;
    }
}


void SecondWindow::on_fullScreen_clicked() {
    if (isFullScreen == false) {
        ui->frame->setWindowFlags(Qt::Window);
        ui->frame->showFullScreen();
        isFullScreen = true;
        this->hide();

    } else {
        this->show();
        ui->frame->setWindowFlags(Qt::Widget);  //    and to go back make it a widget again:
        ui->frame->show();
        isFullScreen = false;
    }
}

void SecondWindow::closeEvent (QCloseEvent *event) {
    QMessageBox::StandardButton resBtn = QMessageBox::question( this, "Quit",
                                                                tr("Are you sure?\n"),
                                                                QMessageBox::No | QMessageBox::Yes,
                                                                QMessageBox::Yes);
    if (resBtn != QMessageBox::Yes) {
        event->ignore();
    } else {
        stop = true;
        event->accept();
    }
}


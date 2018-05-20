#include <iostream>
#include <algorithm>
#include <pthread.h>
#include <functional> // bind

#include <QFile>
#include <QTextStream>
#include <QString>
#include <QStringList>
#include <QHeaderView>
#include <QMessageBox>
#include <QBuffer>
#include <QVideoWidget>
#include <QMediaPlayer>

#include "QCloseEvent"

#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"

#include "Client/supporting/uici.h"
#include "Client/supporting/restart.h"
#include "Client/MatConverter.h"
#include "Client/Client.h"
#include "Client/Command.h"

#include "secondwindow.h"
#include "ui_secondwindow.h"

#define WINDOW_NAME "WINDOW"


SecondWindow::SecondWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SecondWindow)
{
    ui->setupUi(this);

    QHeaderView* header = ui->tableWidget->horizontalHeader();
    header->setSectionResizeMode(QHeaderView::Stretch);

    ui->tableWidget->setColumnCount(2);
    for(int i = 0; i < 2; i++)
        ui->tableWidget->setColumnWidth(i, 257);
    ui->tableWidget->setHorizontalHeaderLabels(QString("Bölge;Tarih").split(";"));
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);    // edit engellemek için
    ui->tableWidget->setSortingEnabled(true);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);  // tüm row'u seçmek için

    loadImages();
    getTableInfo();
}

void SecondWindow::getTableInfo(){
    sql::ResultSet *res = db.getLastFiftyRaport();
    QTableWidget* table = ui->tableWidget;

    int i = 0;
    while (res->next()) {
        table->insertRow(i);

        int area = res->getInt(3);
        string date = res->getString(4);

        QTableWidgetItem *item1 = new QTableWidgetItem();
        item1->setText(QString::fromStdString("Bölge" + to_string(area)));
        table->setItem(i, 0, item1);

        QTableWidgetItem *item2 = new QTableWidgetItem();
        item2->setText(QString::fromStdString(date));
        table->setItem(i, 1, item2);

        ++i;
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

void SecondWindow::callback(Client& client) {
    Mat frame;
    Mat decompressedFrame;
    QImage image1;
    bool connectionActive = true;

    Command command = Command::start;
    if(client.send(&command, sizeof(Command)) != sizeof(Command)) {
        err("client.send()");
        connectionActive = false;
        isSystemRun = false;
    }

    for (;connectionActive;) {

        if (client.hasDataPending()) {
            cout << "Data pending " << client.dataPending() << endl;
        } else {
            cout << "No data pending" << endl;
        }

        if(client.receive(frame)) {
            err("client.receive()");
            connectionActive = false;
        } else {
            pyrUp(frame, decompressedFrame);

            cvtColor(frame, frame, CV_BGR2RGB);    //  renkleri Qt ye uygun hale getirmek için
            image1= QImage((uchar*) frame.data, frame.cols, frame.rows, frame.step, QImage::Format_RGB888);

            if (isLiveStream) {
                ui->video->setPixmap(QPixmap::fromImage(image1));
                ui->video->setScaledContents( true );
                ui->video->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
                ui->video->show();
            } else {
                image1 = QImage();
                ui->video->setPixmap(QPixmap::fromImage(image1));
                ui->video->show();
            }

            if (cv::waitKey(30) >= 0 || !isSystemRun) {
                command = Command::stop;
                if(client.send(&command, sizeof(Command)) != sizeof(Command)) {
                    err("client.send()");
                    connectionActive = false;
                }
                client.disconnectFromServer();
                connectionActive = false;
            }
        }
    }

    image1 = QImage();
    ui->video->setPixmap(QPixmap::fromImage(image1));
    ui->video->show();  // biterken ekranı boşaltmak için*/

}

void SecondWindow::on_baslat_clicked() {
    if(isSystemRun == true) {
        //STOP
        isSystemRun = false;
        isLiveStream = false;
        //QImage image1 = ;
        ui->detectedImage->setPixmap(QPixmap::fromImage(QImage()));
        ui->detectedImage->show();  // biterken ekranı boşaltmak için*/
        ui->baslat->setText("Başlat");
    } else {
        //START
        cout << "- CLIENT STARTED -" << endl;
        auto f = bind(&SecondWindow::callback, this, std::placeholders::_1);

        const string ipAddress = "10.1.130.243";
        const string localIp = "localhost";

        Client client("localhost", f);

        ui->baslat->setText("Durdur");
        isSystemRun = true;
        if (client.connectToServer() == -1) {
            err("client.connect()");
            #if _WIN32
                cout << WSAGetLastError() << endl;
            #endif
            //exit(1);
            isLiveStream = false;
            isSystemRun = false;
            ui->baslat->setText("Başlat");
            QMessageBox msgBox(this);
            msgBox.setStyleSheet("QLabel { color : red; qproperty-alignment: AlignCenter;}");
            msgBox.setWindowTitle("Uyarı!");
            msgBox.setText(tr("Server'a Bağlanılamadı !\n"));
            msgBox.addButton(tr("Tamam"), QMessageBox::YesRole);
            msgBox.exec();
        }

        cout << "- CLIENT EXITED -" << endl;
    }

}

void SecondWindow::on_play_clicked() {
    if(!isLiveStream && isSystemRun){
        isLiveStream = true;
    }
}

void SecondWindow::on_stop_clicked() {
    isLiveStream = false;
    if (isFullScreen) {
        this->show();
        ui->videoPart->setWindowFlags(Qt::Widget);  //    and to go back make it a widget again:
        ui->videoPart->close();
        ui->videoPart->show();
        isFullScreen = false;
    }
}

void SecondWindow::on_fullScreen_clicked() {
    if (isLiveStream) {   // sadece canlı yayın açıkken
        if (!isFullScreen) {
            ui->videoPart->setWindowFlags(Qt::Window);
            ui->videoPart->showFullScreen();
            isFullScreen = true;
            this->hide();

        } else {
            this->show();
            ui->videoPart->setWindowFlags(Qt::Widget);  //    and to go back make it a widget again:
            ui->videoPart->close();
            ui->videoPart->show();
            isFullScreen = false;
        }
    }
}

void SecondWindow::on_bolgeGrafigi_clicked() {
    graph = new Graphs(this, db.getCountByArea());
    graph->setWindowTitle("Bölge Grafiği");
    graph->show();
}

void SecondWindow::on_openDateGraph_clicked() {
    graph = new Graphs(this, db.getDateByArea());
    graph->setWindowTitle("Tarih Grafiği");
    graph->show();
}

void SecondWindow::on_tableWidget_cellDoubleClicked(int row, int column) {
    if (isSystemRun) {
        ui->detectedImage->setPixmap(QPixmap(":/Resources/images/gtu.png"));     // basılan row biliniyor , ona göre db den foto alınacak
        ui->detectedImage->setScaledContents(true);
        ui->detectedImage->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
    }
}

void SecondWindow::closeEvent (QCloseEvent *event) {

    QMessageBox msgBox(this);
    msgBox.setStyleSheet("QLabel { color : red; qproperty-alignment: AlignCenter;}");
    msgBox.setWindowTitle("Çıkış!");
    msgBox.setText(tr("Emin misin ?\n"));
    QPushButton *yes = msgBox.addButton(tr("Evet"), QMessageBox::YesRole);
    msgBox.addButton(tr("Hayır"), QMessageBox::NoRole);
    msgBox.exec();

    if (msgBox.clickedButton() != yes) {
        event->ignore();
    } else {
        isLiveStream = false;
        event->accept();
    }
}

SecondWindow::~SecondWindow() {
    delete ui;
}

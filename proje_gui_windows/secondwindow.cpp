#include <iostream>
#include <algorithm>
#include <sstream>
#include <pthread.h>
#include <functional> // bind

#include <QString>
#include <QStringList>
#include <QHeaderView>
#include <QMessageBox>
#include <QBuffer>
#include <QVideoWidget>
#include <QMediaPlayer>
#include <QTimer>
#include <QThread>
#include <QtConcurrent/QtConcurrent>

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
#define UPDATE_SECOND 10

//const string ipAddress = "192.168.2.2";
const string ipAddress = "192.168.1.7";
//const string ipAddress = "";

bool PROFILE_PROD = false;
bool inf = true;

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

    auto f = bind(&SecondWindow::callback, this, std::placeholders::_1);

    client = new Client(ipAddress, f);

    QTimer::singleShot(27, this, SLOT(runLiveStream()));

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTableInfo()));
    timer->start(UPDATE_SECOND * 1000);


}

void SecondWindow::runLiveStream(){
   while (inf) {
        if (client->connectToServer() == -1) {
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
            QPushButton *reconnect = msgBox.addButton(tr("Yeniden Bağlan"), QMessageBox::YesRole);
            msgBox.addButton(tr("Çıkış"), QMessageBox::NoRole);
            msgBox.exec();
            if (msgBox.clickedButton() != reconnect) {
                this->close();
            }
            else {
                isLiveStream = true;
            }
        }
    }
}

void SecondWindow::getTableInfo(){
    QSqlQuery query = db.getLastFiftyRaport();
    QTableWidget* table = ui->tableWidget;

    int i = 0;
    while (query.next()) {
        if (table->rowCount() < 50)
            table->insertRow(i);

        //id setlenmeli, kullanıcı çift tıkladığında bu id ye göre db.getImage(id) methodu ile image alınabilir.
        int id = query.value(0).toInt();
        int areaId = query.value(1).toInt();
        string date = query.value(2).toString().toStdString();

        QTableWidgetItem *item1 = new QTableWidgetItem();
        item1->setText(QString::fromStdString("Bölge" + to_string(areaId)));
        item1->setData(Qt::UserRole, id);
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
    bool isFirstImg = true;
    int noHelmetAreaId = 0;


    Command command;

    for (;connectionActive;) {
        /*if (client.hasDataPending()) {
            cout << "Data pending " << client.dataPending() << endl;
        } else {
            cout << "No data pending" << endl;
        }*/

        if(client.receive(&command, sizeof(Command)) != sizeof(Command)) {
            err("server.receive()");
            connectionActive = false;
        } else if (command == Command::no_helmet && client.receive(&noHelmetAreaId, sizeof(int)) != sizeof(int)) {
            err("client.receive()");
            connectionActive = false;
        } else if(client.receive(frame)) {
            err("client.receive()");
            connectionActive = false;
        } else {

            switch (command) {
                case Command::none: {
                    cv::pyrUp(frame, decompressedFrame);
                    cvtColor(decompressedFrame, decompressedFrame, CV_BGR2RGB);    //  renkleri Qt ye uygun hale getirmek için

                    image1= QImage((uchar*) decompressedFrame.data, decompressedFrame.cols, decompressedFrame.rows, decompressedFrame.step, QImage::Format_RGB888);

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

                }
                    break;
                case Command::no_helmet: {
                    cout << command << " " << noHelmetAreaId << endl; // FRAME WITH BLUE AND RED SQUARES HAS ARRIVED
                    if (PROFILE_PROD) {
                        QtConcurrent::run(this->db, &DbConnection::postReport, noHelmetAreaId, frame);
                    }
                    ui->detectedImage->setPixmap(QPixmap::fromImage(QImage((unsigned char*) frame.data, frame.cols, frame.rows, QImage::Format_RGB888)));
                    ui->detectedImage->setScaledContents(true);
                    ui->detectedImage->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
                }
                    break;
                case Command::init_point:{
                    ui->baslat->setVisible(true);
                }
                    break;
            }

            if (isSystemRun && isStopClicked) {
                command = Command::start;
                if(client.send(&command, sizeof(Command)) != sizeof(Command)) {
                    err("client.send()");
                    connectionActive = false;
                    isSystemRun = false;
                }
                isStopClicked = false;
            }
            if (!isSystemRun && isStopClicked) {
                command = Command::stop;
                if(client.send(&command, sizeof(Command)) != sizeof(Command)) {
                    err("client.send()");
                    connectionActive = false;
                }
                ui->baslat->setVisible(false);
                isStopClicked = false;
            }


            if (cv::waitKey(30) >= 0) {
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
        //QImage image1 = ;
        ui->detectedImage->setPixmap(QPixmap::fromImage(QImage()));
        ui->detectedImage->show();  // biterken ekranı boşaltmak için*/
        ui->baslat->setText("Başlat");
    } else {
        //START
        ui->baslat->setText("Durdur");
        isSystemRun = true;
    }
    isStopClicked = true;

}

void SecondWindow::on_play_clicked() {
    isLiveStream = true;
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
    if(graph != nullptr)
        delete graph;

    graph = new Graphs(this, db.getCountByArea());
    graph->setWindowTitle("Bölge Grafiği");
    graph->show();    
}

void SecondWindow::on_openDateGraph_clicked() {
    if(graph != nullptr)
        delete graph;

    graph = new Graphs(this, db.getDateByArea());
    graph->setWindowTitle("Tarih Grafiği");
    graph->show();
}

void SecondWindow::on_tableWidget_cellDoubleClicked(int row, int column) {
    if (isSystemRun) {
        int id = ui->tableWidget->item(row, 0)->data(Qt::UserRole).toInt();;
        QImage image = db.getImage(id);

        if(detectedImage != nullptr)
            delete detectedImage;

        detectedImage = new DetectedImage(this, image);
        detectedImage->setWindowTitle("Tespit Edilen Resim");
        detectedImage->show();
    }
}

void SecondWindow::updateTableInfo() {
    this->getTableInfo();
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
        isSystemRun = false;
        isLiveStream = false;
        inf = false;
        QTimer::singleShot(0, this, SLOT(disconnect()));
        event->accept();
    }
}

void SecondWindow::disconnect(){
    client->disconnectFromServer();
}

SecondWindow::~SecondWindow() {
    if(detectedImage != nullptr)
        delete detectedImage;

    if(graph != nullptr)
        delete graph;

    delete client;
    delete ui;
}


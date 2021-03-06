#include <iostream>
#include <algorithm>
#include <sstream>
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
#include <QTimer>
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

#include <cppconn/prepared_statement.h>
#include <QThread>

#define WINDOW_NAME "WINDOW"
#define UPDATE_SECOND 10

//const string ipAddress = "192.168.2.2";
const string ipAddress = "localhost";

bool PROFILE_PROD = true;
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

    ui->openDateGraph->setVisible(false);

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
    sql::ResultSet *res = db.getLastFiftyRaport();
    QTableWidget* table = ui->tableWidget;

    int i = 0;
    while (res->next()) {
        if (table->rowCount() < 50)
            table->insertRow(i);

        //id setlenmeli, kullanıcı çift tıkladığında bu id ye göre db.getImage(id) methodu ile image alınabilir.
        int id = res->getInt(1);
        int areaId = res->getInt(2);
        string date = res->getString(3);

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


    QImage image2(":/Resources/images/gtu.png");
    ui->gtu->setPixmap(QPixmap::fromImage(image2));
    ui->gtu->setScaledContents(true);
    ui->gtu->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);


    QImage image3(":/Resources/images/dikkat.png");
    ui->dikkat1->setPixmap(QPixmap::fromImage(image3));
    ui->dikkat1->setScaledContents(true);
    ui->dikkat1->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    ui->dikkat2->setPixmap(QPixmap::fromImage(image3));
    ui->dikkat2->setScaledContents(true);
    ui->dikkat2->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);


    QPixmap *image = new QPixmap(":/Resources/images/play.png");
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

void push(int area, Mat &image){
    DbConnection dbcon;
    dbcon.postReport(area, image);
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
                    pyrUp(frame, decompressedFrame);
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
                        isFirstImg = false;
                        QtConcurrent::run(push, noHelmetAreaId, frame);
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
    QImage image;
    Mat frame, decompressedFrame;
    int id;
    DbConnection dbconn;

    id = ui->tableWidget->item(row, 0)->data(Qt::UserRole).toInt();
    frame = dbconn.getImage(id);
    pyrUp(frame, decompressedFrame);
    cvtColor(decompressedFrame, decompressedFrame, CV_BGR2RGB);    //  renkleri Qt ye uygun hale getirmek için

    image = QImage((uchar*) decompressedFrame.data, decompressedFrame.cols, decompressedFrame.rows, decompressedFrame.step, QImage::Format_RGB888);

    if(detectedImage != nullptr)
        delete detectedImage;

    detectedImage = new DetectedImage(this, image);
    detectedImage->setWindowTitle("Tespit Edilen Resim");
    detectedImage->show();
}

void SecondWindow::updateTableInfo() {
    cout << "Updated" << endl;
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


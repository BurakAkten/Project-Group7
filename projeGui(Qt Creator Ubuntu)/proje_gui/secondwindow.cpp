#include "secondwindow.h"
#include "ui_secondwindow.h"

#include <QFile>
#include <QTextStream>
#include <QString>
#include <QStringList>
#include <QHeaderView>

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
    sql::ResultSet *res = db.getLastFiftyRaport();
    while (res->next()) {
        /* Access column data by numeric offset, 1 is the first column */
        cout << "Col 1: " << res->getString(1) << endl;
        cout << "Col 2: " << res->getString(2) << endl;
        cout << "Col 3: " << res->getString(3) << endl;
      }

    ui->tableWidget->setColumnCount(2);
    for(int i = 0; i < 2; i++)
        ui->tableWidget->setColumnWidth(i, 257);

    ui->tableWidget->setHorizontalHeaderLabels(QString("Bölge;Tarih").split(";"));
    QHeaderView* header = ui->tableWidget->horizontalHeader();
    header->setSectionResizeMode(QHeaderView::Stretch);

    ui->listWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);     // edit engellemek için
    ui->listWidget->setSelectionMode(QAbstractItemView::ExtendedSelection); // çoklu seçim için
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);    // edit engellemek için
    ui->tableWidget->setSortingEnabled(true);
    getTableInfo();
    getListInfo();

    ui->sec->setVisible(false);
}

SecondWindow::~SecondWindow()
{
    delete ui;
}

void SecondWindow::on_secVeBaslat_clicked()
{
    //RUN THE SYSTEM

    QList<QListWidgetItem*> items;
    int size, i;

    items = ui->listWidget->selectedItems();
    size = items.size();


    if(isSystemRun == true){
        ui->label_3->setText("Bölgeler");
        ui->label_3->setStyleSheet("QLabel { color : black; }");

        ui->ekle->setVisible(true);
        ui->cikar->setVisible(true);
        ui->secVeBaslat->setText("Seç ve Başlat");
        ui->sec->setVisible(false);
        isSystemRun = false;
        isLiveStream = false;
    }
    else if (size != 0 && isSystemRun == false) {
        ui->label_3->setText("Bölgeler");
        ui->label_3->setStyleSheet("QLabel { color : black; }");

        ui->ekle->setVisible(false);
        ui->cikar->setVisible(false);
        ui->secVeBaslat->setText("Durdur");
        ui->sec->setVisible(true);
        isSystemRun = true;

        Region *arr = new Region[size];
        i=0;
        foreach(QListWidgetItem * item, items)
        {
            Region reg = item->data(Qt::UserRole).value<Region>();
            arr[i++] = reg;
        }
        // send  arr to server

        delete [] arr;

    }
    else
    {
        ui->label_3->setText("Lütfen Bölge Seçin !");
        ui->label_3->setStyleSheet("QLabel { color : red; }");
        ui->label_3->setAlignment(Qt::AlignCenter);
    }

}

void SecondWindow::on_bolgeGrafigi_clicked() {
    graph = new Graphs(this, raports, 1);
    graph->setWindowTitle("Bölge Grafiği");
    graph->show();
}

void SecondWindow::on_openDateGraph_clicked() {
    graph = new Graphs(this, raports, 2);
    graph->setWindowTitle("Tarih Grafiği");
    graph->show();
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
/*
    QString line;
    QStringList tokens;
    for (int i = listSize; i < lineNumber; ++i) {    // satır split edildi ve bölge adı listeye eklendi
        line = in.readLine();
        QRegExp sep(";");
        tokens =  line.split(sep);
        QListWidgetItem *item = new QListWidgetItem();
        item->setText(tokens.at(0));
        list->addItem(item);
    }*/

    QString line;
    QStringList tokens;
    for (int i = listSize; i < lineNumber; ++i) {    // satır split edildi ve bölge adı listeye eklendi
        line = in.readLine();
        QRegExp sep(";");
        tokens =  line.split(sep);

        Region region;
        region.name = ((QString)tokens.at(0)).toStdString();
        region.x    = ((QString)tokens.at(1)).toDouble();
        region.y    = ((QString)tokens.at(2)).toDouble();


        QListWidgetItem *item = new QListWidgetItem();
        item->setData(Qt::UserRole ,QVariant::fromValue(region));
        item->setText(tokens.at(0));
        list->addItem(item);
    }

    list->viewport()->repaint();
    return;
}

void SecondWindow::getTableInfo(){

    /*QTextStream out(stdout);
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
    in.seek(0);*/


    sql::ResultSet *res = db.getLastFiftyRaport();


    QTableWidget* table = ui->tableWidget;
    //int rowSize = res->rowsCount();

    this->raports.clear();
    QString line;
    QStringList tokens;
    int i = 0;
    while (res->next()) {    // yeni row eklendi ve yeni itemler tabloya eklendi
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

                if (cv::waitKey(30) >= 0 || isLiveStream == false || isSystemRun == false) {
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


    if(isLiveStream == false && isSystemRun){
        auto f = bind(&SecondWindow::callback, this, std::placeholders::_1);


        cout << "- CLIENT STARTED -" << endl;

        const string ipAddress = "10.1.130.243";
        const string localIp = "localhost";

        Client client(localIp, f);

        isLiveStream = true;
        if (client.connectToServer()) {
            err("client.connect()");
            #if _WIN32
                cout << WSAGetLastError() << endl;
            #endif
            exit(1);
        }

        cout << "- CLIENT EXITED -" << endl;
    }

}


void SecondWindow::on_stop_clicked() {
    isLiveStream = false;
    if (isFullScreen == true) {
        this->show();
        ui->frame->setWindowFlags(Qt::Widget);  //    and to go back make it a widget again:
        ui->frame->show();
        isFullScreen = false;
    }
}


void SecondWindow::on_fullScreen_clicked() {
    if(isLiveStream){   // sadece canlı yayın açıkken
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
}

void SecondWindow::closeEvent (QCloseEvent *event) {
    QMessageBox::StandardButton resBtn = QMessageBox::question( this, "Quit",
                                                                tr("Are you sure?\n"),
                                                                QMessageBox::No | QMessageBox::Yes,
                                                                QMessageBox::Yes);
    if (resBtn != QMessageBox::Yes) {
        event->ignore();
    } else {
        isLiveStream = false;
        event->accept();
    }
}


void SecondWindow::on_ekle_clicked()
{
    bolge = new BolgeEkle(this, ui->listWidget);
    bolge->show();

}

void SecondWindow::on_cikar_clicked()
{
    QList<QListWidgetItem*> items = ui->listWidget->selectedItems();
    QString selected="";
    foreach(QListWidgetItem * item, items)
    {
        selected += item->text()+" ";
    }

    QMessageBox::StandardButton reply;

    reply = QMessageBox::question(this, "Çıkar", selected+" silinecek, emin misin?",
         QMessageBox::Yes | QMessageBox::Cancel);

    if (reply == QMessageBox::Yes) {
        qDeleteAll(ui->listWidget->selectedItems());

        int listSize = ui->listWidget->count();
        string lines = "regionName;X;Y\n";

        for (int i = 0; i < listSize; ++i) {
            QListWidgetItem* item = ui->listWidget->item(i);
            Region reg = item->data(Qt::UserRole).value<Region>();
            lines += reg.name + ";" + to_string(reg.x) + ";" + to_string(reg.y) + "\n";
        }

        QFile file("/home/furkan/Qt Projects/proje_gui/Files/coordinates.csv");
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream stream(&file);
            stream << QString::fromStdString(lines);
        }
    }
    if (reply == QMessageBox::Discard)
    {
        // toDo
    }
}

void SecondWindow::on_sec_clicked()
{
    QList<QListWidgetItem*> items;
    int size, i;

    items = ui->listWidget->selectedItems();
    size = items.size();

    if(size != 0){
        Region *arr = new Region[size];
        i=0;
        foreach(QListWidgetItem * item, items)
        {
            Region reg = item->data(Qt::UserRole).value<Region>();
            arr[i++] = reg;
        }
        // send  arr to server

        delete [] arr;
    }
}

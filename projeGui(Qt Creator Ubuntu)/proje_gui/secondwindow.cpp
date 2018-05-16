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

#include <algorithm>

#define WINDOW_NAME "WINDOW"


SecondWindow::SecondWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SecondWindow)
{

    ui->setupUi(this);

    loadImages();

    ui->tableWidget->setColumnCount(2);
    for(int i = 0; i < 2; i++)
        ui->tableWidget->setColumnWidth(i, 257);

    ui->tableWidget->setHorizontalHeaderLabels(QString("Bölge;Tarih").split(";"));
    QHeaderView* header = ui->tableWidget->horizontalHeader();
    header->setSectionResizeMode(QHeaderView::Stretch);

    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);    // edit engellemek için
    ui->tableWidget->setSortingEnabled(true);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);  // tüm row'u seçmek için

    ui->listWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);     // edit engellemek için
    ui->listWidget->setSelectionMode(QAbstractItemView::ExtendedSelection); // çoklu seçim için
    getTableInfo();
    getListInfo();

    getBoxInfo();
    ui->comboBox->setCurrentIndex(-1);

   // ui->detectedImage->setVisible(false);
    ui->cikar->setVisible(false);
    ui->ekle->setVisible(false);
    //ui->ekle->setText("Düzenle"); // Düzenle butonu

    ui->listWidget->setVisible(false); // bölge listesi
    ui->label_3->setVisible(false);    // bölge etiketi


}

SecondWindow::~SecondWindow()
{
    delete ui;
}

void SecondWindow::on_baslat_clicked()
{
    //RUN THE SYSTEM

    QList<QListWidgetItem*> items;
    int size, i;

    items = ui->listWidget->selectedItems();
    size = items.size();


    if(isSystemRun == true){    // sistem durduruldu, (durdur clicked)
        //ui->label_3->setText("Bölgeler");
        //ui->label_3->setStyleSheet("QLabel { color : black; }");

        //ui->ekle->setVisible(true);
        //ui->cikar->setVisible(true);
        ui->baslat->setText("Başlat");
        isSystemRun = false;
        isLiveStream = false;
        //QImage image1 = ;
        ui->detectedImage->setPixmap(QPixmap::fromImage(QImage()));
        ui->detectedImage->show();  // biterken ekranı boşaltmak için*/
    }
    else /*if (size != 0 && isSystemRun == false)*/ {
        //ui->label_3->setText("Bölgeler");
        //ui->label_3->setStyleSheet("QLabel { color : black; }");

        //ui->ekle->setVisible(false);
        //ui->cikar->setVisible(false);
        ui->baslat->setText("Durdur");
        isSystemRun = true;

        /*
        Region *arr = new Region[size];
        i=0;
        foreach(QListWidgetItem * item, items)
        {
            Region reg = item->data(Qt::UserRole).value<Region>();
            arr[i++] = reg;
        }
        delete [] arr; */

        // send  arr to server  , size = i


    }/*
    else
    {
        QMessageBox msgBox(this);
        msgBox.setStyleSheet("QLabel { color : red; qproperty-alignment: AlignCenter;}");
        msgBox.setWindowTitle("Uyarı!");
        msgBox.setText(tr("Lütfen Bölge Seçin !\n"));
        msgBox.addButton(tr("Tamam"), QMessageBox::YesRole);
        msgBox.exec();
        return;
        /*  ui->label_3->setText("Lütfen Bölge Seçin !");
        ui->label_3->setStyleSheet("QLabel { color : red; }");
        ui->label_3->setAlignment(Qt::AlignCenter);
    }*/

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

void SecondWindow::getBoxInfo(){

    sql::ResultSet *res = db.getAllAreas();
    QComboBox* comboB = ui->comboBox;
    int i = 1;

    while (res->next()) {
        Region region;
        region.name = "Bölge " + to_string(res->getInt(1));
        region.x1 = res->getInt(2);
        region.x2 = res->getInt(3);
        region.y = res->getInt(4);

        comboB->addItem(QString::fromStdString(region.name) , QVariant::fromValue(region));
        ++i;
    }

    comboB->repaint();
    return;
}

void SecondWindow::getListInfo(){

    /*QTextStream out(stdout);
    QFile file(":/Resources/Files/coordinates.csv");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        out << "File is not opened!!" << endl;
        return;
    }

    QTextStream in(&file);
    in.readLine();              // ilk satır okunmadı

    QListWidget* list = ui->listWidget;
    QString line;
    QStringList tokens;
    while (!in.atEnd()) {        // satır split edildi ve bölge adı listeye eklendi
        line = in.readLine();
        QRegExp sep(";");
        tokens =  line.split(sep);

        Region region;
        region.name = ((QString)tokens.at(0)).trimmed().toStdString();
        region.x    = ((QString)tokens.at(1)).trimmed().replace(",",".").toDouble();
        region.y    = ((QString)tokens.at(2)).trimmed().replace(",",".").toDouble();

        //out << QString::fromStdString(region.name) <<" " << QString::fromStdString(to_string(region.x)) <<" "   << QString::fromStdString(to_string(region.y)) <<"\n" ;
        QListWidgetItem *item = new QListWidgetItem();
        item->setData(Qt::UserRole ,QVariant::fromValue(region));
        item->setText(tokens.at(0));
        list->addItem(item);
    }

    list->viewport()->repaint();
    return;*/

    sql::ResultSet *res = db.getAllAreas();
    QListWidget* list = ui->listWidget;
    int i = 1;

    while (res->next()) {
        Region region;
        region.name = "Bölge " + to_string(res->getInt(1));
        region.x1 = res->getInt(2);
        region.x2 = res->getInt(3);
        region.y = res->getInt(4);

        QListWidgetItem *item = new QListWidgetItem();
        item->setData(Qt::UserRole ,QVariant::fromValue(region));
        item->setText(QString::fromStdString(region.name));
        list->addItem(item);
        ++i;
    }

    list->viewport()->repaint();
    return;
}

void SecondWindow::getTableInfo(){

    sql::ResultSet *res = db.getLastFiftyRaport();

    QTableWidget* table = ui->tableWidget;
    //int rowSize = res->rowsCount();

    this->raports.clear();
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
    //ui->gtu->setPixmap(QPixmap(":/Resources/images/gtu.png"));
    //ui->gtu->setScaledContents(true);
    //ui->gtu->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );


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

                if (cv::waitKey(30) >= 0 || !isLiveStream || !isSystemRun) {
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


    if(!isLiveStream && isSystemRun){
        auto f = bind(&SecondWindow::callback, this, std::placeholders::_1);


        cout << "- CLIENT STARTED -" << endl;

        const string ipAddress = "10.1.130.243";
        const string localIp = "localhost";

        Client client("localhost", f);

        isLiveStream = true;
        if (client.connectToServer() == -1) {
            err("client.connect()");
            #if _WIN32
                cout << WSAGetLastError() << endl;
            #endif
            //exit(1);
            isLiveStream = false;
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
    if(isLiveStream){   // sadece canlı yayın açıkken
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


void SecondWindow::on_ekle_clicked()    // edit region
{
    QTextStream out(stdout);
    /*
    bolge = new BolgeEkle(this, ui->listWidget);
    bolge->show();*/

    int index = ui->comboBox->currentIndex();

    if(index != -1)
    {
        QVariant item = ui->comboBox->itemData(index);
        Region currRegion= item.value<Region>();

        region = new EditRegion(this, &currRegion);
        region->exec();

        ui->comboBox->setItemData(index, QVariant::fromValue(currRegion));
        db.updateArea(currRegion);
    }
    else {
        QMessageBox msgBox(this);
        msgBox.setStyleSheet("QLabel { color : red; qproperty-alignment: AlignCenter;}");
        msgBox.setWindowTitle("Uyarı!");
        msgBox.setText(tr("Lütfen Düzenlenecek Bölge Seçin !\n"));
        msgBox.addButton(tr("Tamam"), QMessageBox::YesRole);
        msgBox.exec();
        return;
    }


}

void SecondWindow::on_cikar_clicked()
{
    QList<QListWidgetItem*> items = ui->listWidget->selectedItems();
    if(items.size() == 0){

        QMessageBox msgBox(this);
        msgBox.setStyleSheet("QLabel { color : red; qproperty-alignment: AlignCenter;}");
        msgBox.setWindowTitle("Uyarı!");
        msgBox.setText(tr("Lütfen Çıkarılacak Bölge Seçin !\n"));
        msgBox.addButton(tr("Tamam"), QMessageBox::YesRole);
        msgBox.exec();
        return;
    }

    QString selected="";
    foreach(QListWidgetItem * item, items)
    {
        selected += item->text()+" ";
    }


    QMessageBox msgBox(this);
    msgBox.setStyleSheet("QLabel { color : red; qproperty-alignment: AlignCenter;}");
    msgBox.setWindowTitle("Çıkar");
    msgBox.setText(selected+" silinecek, emin misin?\n");
    QPushButton *yes = msgBox.addButton(tr("Evet"), QMessageBox::YesRole);
    msgBox.addButton(tr("İptal"), QMessageBox::NoRole);
    msgBox.exec();

    if (msgBox.clickedButton() == yes)
    {
        qDeleteAll(ui->listWidget->selectedItems());

        int listSize = ui->listWidget->count();
        string lines = "regionName;X;Y\n";

        for (int i = 0; i < listSize; ++i) {
            QListWidgetItem* item = ui->listWidget->item(i);
            Region reg = item->data(Qt::UserRole).value<Region>();
            //lines += reg.name + ";" + to_string(reg.x) + ";" + to_string(reg.y) + "\n";
        }

        QFile file("/home/furkan/Qt Projects/proje_gui/Files/coordinates.csv");
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream stream(&file);
            stream << QString::fromStdString(lines);
        }
    }
}
/*
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
}*/


void SecondWindow::on_tableWidget_cellDoubleClicked(int row, int column)
{
    QTextStream out(stdout);
    out << "double clicked to table" << endl;

    if(isSystemRun) // sistem çalışıyorsa
    {
        ui->label_3->setText("Yakalanan Resim");
        ui->label_3->setStyleSheet("QLabel { color : red; }");
        ui->label_3->setAlignment(Qt::AlignCenter);

        //ui->label_3->setVisible(false);
        ui->listWidget->setVisible(false);
        ui->detectedImage->setVisible(true);


        ui->detectedImage->setPixmap(QPixmap(":/Resources/images/gtu.png"));     // basılan row biliniyor , ona göre db den foto alınacak
        ui->detectedImage->setScaledContents(true);
        ui->detectedImage->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
    }


}

void SecondWindow::on_comboBox_activated(int index)
{
    QTextStream out(stdout);
    if(index == 0){
        out << ui->comboBox->currentText() << endl;     // get info from db
    }
    else if (index == 1) {
        out << ui->comboBox->currentText() << endl;     // get info from db
    }
    else if (index == 2) {
        out << ui->comboBox->currentText() << endl;     // get info from db
    }
    else if (index == 3) {
        out << ui->comboBox->currentText() << endl;     // get info from db
    }
    else
    {
        out << ui->comboBox->currentText() << endl;     // get info from db
    }
}

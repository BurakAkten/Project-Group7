#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include "graphs.h"
#include "bolgeekle.h"
#include "rapor.h"

#include "Client/Client.h"

using namespace std;
using namespace server_client;

/*
typedef struct Regions
{
    string name;
    double x;
    double y;
}Regions;
*/

namespace Ui {
class SecondWindow;
}

class SecondWindow : public QMainWindow
{
    Q_OBJECT

public:
    //friend void callback(Client& client);
    explicit SecondWindow(QWidget *parent = 0);
    ~SecondWindow();

private slots:
    void on_secVeBaslat_clicked();

    void on_bolgeGrafigi_clicked();

    void on_openDateGraph_clicked();

    void on_play_clicked();

    void on_stop_clicked();

    void on_fullScreen_clicked();

    void on_ekle_clicked();

    void on_cikar_clicked();

private:
    bool isSystemRun = false;
    bool isLiveStream = false;
    bool isFullScreen = false;
    Ui::SecondWindow *ui;
    vector<Rapor> raports;
   // vector<Regions> regions;
    Graphs* graph;
    BolgeEkle* bolge;
    QSqlDatabase db;
    void getTableInfo();
    void getListInfo();
    void loadImages();
    void callback(Client& client);
    void closeEvent (QCloseEvent *event);
};

#endif // SECONDWINDOW_H

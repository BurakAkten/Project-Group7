#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QMainWindow>
#include "graphs.h"
#include "bolgeekle.h"
#include "editregion.h"
#include "rapor.h"
#include "dbconnection.h"

#include "Client/Client.h"

#include "region.h"


using namespace std;
using namespace server_client;


namespace Ui {
class SecondWindow;
}

class SecondWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SecondWindow(QWidget *parent = 0);
    ~SecondWindow();

private slots:
    void on_baslat_clicked();

    void on_bolgeGrafigi_clicked();

    void on_openDateGraph_clicked();

    void on_play_clicked();

    void on_stop_clicked();

    void on_fullScreen_clicked();

    void on_tableWidget_cellDoubleClicked(int row, int column); 

    void updateTableInfo();

private:
    bool isSystemRun = false;
    bool isLiveStream = false;
    bool isFullScreen = false;
    Ui::SecondWindow *ui;
    Graphs* graph;
    DbConnection db;
    void getTableInfo();
    void loadImages();
    void callback(Client& client);
    void closeEvent (QCloseEvent *event);
};

#endif // SECONDWINDOW_H

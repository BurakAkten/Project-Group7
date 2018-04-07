#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QMainWindow>
#include "bolgeekle.h"

#include "Client/Client.h"

using namespace std;
using namespace server_client;

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
    void on_bolge_sec_2_clicked();
    void on_bolge_ekle_2_clicked();

    void on_play_clicked();

    void on_stop_clicked();

private:
    bool stop=false;
    Ui::SecondWindow *ui;
    BolgeEkle* bolge;
    void getTableInfo();
    void getListInfo();
    void loadImages();
    void callback(Client& client);
    void closeEvent (QCloseEvent *event);
};

#endif // SECONDWINDOW_H

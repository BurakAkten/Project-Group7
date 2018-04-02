#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QMainWindow>
#include "bolgeekle.h"

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
    void on_bolge_sec_2_clicked();
    void on_bolge_ekle_2_clicked();

private:
    Ui::SecondWindow *ui;
    BolgeEkle* bolge;
    void getTableInfo();
    void getListInfo();
    void loadImages();
};

#endif // SECONDWINDOW_H

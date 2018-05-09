#ifndef BOLGEEKLE_H
#define BOLGEEKLE_H

#include <QDialog>
#include <QListWidget>

#include "region.h"


namespace Ui {
class BolgeEkle;
}

class BolgeEkle : public QDialog
{
    Q_OBJECT

public:
    explicit BolgeEkle(QWidget *parent = 0);
    explicit BolgeEkle(QWidget *parent=0, QListWidget* list=0);
    ~BolgeEkle();

private slots:
    void on_ekle_clicked();

private:
    Ui::BolgeEkle *ui;
    QListWidget *listWidget;
};

#endif // BOLGEEKLE_H

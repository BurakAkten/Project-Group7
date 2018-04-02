#ifndef BOLGEEKLE_H
#define BOLGEEKLE_H

#include <QDialog>

namespace Ui {
class BolgeEkle;
}

class BolgeEkle : public QDialog
{
    Q_OBJECT

public:
    explicit BolgeEkle(QWidget *parent = 0);
    ~BolgeEkle();

private slots:
    void on_pushButton_clicked();

private:
    Ui::BolgeEkle *ui;
};

#endif // BOLGEEKLE_H

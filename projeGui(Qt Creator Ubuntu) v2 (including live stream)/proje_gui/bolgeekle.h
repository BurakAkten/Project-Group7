#ifndef BOLGEEKLE_H
#define BOLGEEKLE_H

#include <QDialog>
#include "rapor.h"

namespace Ui {
class BolgeEkle;
}

class BolgeEkle : public QDialog
{
    Q_OBJECT

public:
    BolgeEkle(QWidget *parent, vector<Rapor> raports, int graphType);
    ~BolgeEkle();

private:
    Ui::BolgeEkle *ui;
    vector<Rapor> raports;
    int raportNumberByArea[4] = {0, 0, 0, 0};
    void createAreaGraph();
    void createDateGraph();
    void setRaportNumberByArea();
};

#endif // BOLGEEKLE_H

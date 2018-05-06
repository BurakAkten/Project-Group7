#ifndef GRAPHS_H
#define GRAPHS_H

#include <QDialog>
#include "rapor.h"

namespace Ui {
class Graphs;
}

class Graphs : public QDialog
{
    Q_OBJECT

public:
    Graphs(QWidget *parent, vector<Rapor> raports, int graphType);
    ~Graphs();

private:
    Ui::Graphs *ui;
    vector<Rapor> raports;
    int raportNumberByArea[4] = {0, 0, 0, 0};
    void createAreaGraph();
    void createDateGraph();
    void setRaportNumberByArea();
};

#endif // GRAPHS_H

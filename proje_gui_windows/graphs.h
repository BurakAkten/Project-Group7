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
    Graphs(QWidget *parent, vector<int> areaCounts);
    Graphs(QWidget *parent, map<string, int> dateByAreas);
    ~Graphs();

private:
    Ui::Graphs *ui;
    void createAreaGraph(vector<int> areaCounts);
    void createDateGraph(map<string, int> dateByAreas);
};

#endif // GRAPHS_H

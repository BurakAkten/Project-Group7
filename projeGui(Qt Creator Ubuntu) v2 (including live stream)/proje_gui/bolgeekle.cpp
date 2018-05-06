#include "bolgeekle.h"
#include "ui_bolgeekle.h"

#include <string>
#include <iostream>

#include "QMessageBox"
#include "QString"
#include "QDebug"

using namespace std;

BolgeEkle::BolgeEkle(QWidget *parent, vector<Rapor> raports, int graphType) :
    QDialog(parent),
    ui(new Ui::BolgeEkle)
{
    ui->setupUi(this);
    this->raports = raports;
    switch (graphType) {
    case 1: {
        setRaportNumberByArea();
        BolgeEkle::createAreaGraph();
        break;
    }
    case 2: {
        BolgeEkle::createDateGraph();
        break;
    }
    }

}

BolgeEkle::~BolgeEkle()
{
    delete ui;
}

void BolgeEkle::createAreaGraph() {
    // set dark background gradient:
    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(90, 90, 90));
    gradient.setColorAt(0.38, QColor(105, 105, 105));
    gradient.setColorAt(1, QColor(70, 70, 70));
    ui->customPlot->setBackground(QBrush(gradient));

    // create empty bar chart objects:
    //QCPBars *regen = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
    //QCPBars *nuclear = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
    QCPBars *raportNumber = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
    //regen->setAntialiased(false); // gives more crisp, pixel aligned bar borders
    //nuclear->setAntialiased(false);
    raportNumber->setAntialiased(false);
    //regen->setStackingGap(1);
    //nuclear->setStackingGap(1);
    raportNumber->setStackingGap(1);
    // set names and colors:
    raportNumber->setName("Rapor Sayısı");
    raportNumber->setPen(QPen(QColor(111, 9, 176).lighter(170)));
    raportNumber->setBrush(QColor(111, 9, 176));
    /*nuclear->setName("Nuclear");
    nuclear->setPen(QPen(QColor(250, 170, 20).lighter(150)));
    nuclear->setBrush(QColor(250, 170, 20));
    regen->setName("Regenerative");
    regen->setPen(QPen(QColor(0, 168, 140).lighter(130)));
    regen->setBrush(QColor(0, 168, 140));
    // stack bars on top of each other:
    nuclear->moveAbove(fossil);
    regen->moveAbove(nuclear);*/

    // prepare x axis with country labels:
    QVector<double> ticks;
    QVector<QString> labels;
    ticks << 1 << 2 << 3 << 4;
    labels << "Bölge 1" << "Bölge 2" << "Bölge  3" << "Bölge 4";
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, labels);
    ui->customPlot->xAxis->setTicker(textTicker);
    ui->customPlot->xAxis->setTickLabelRotation(60);
    ui->customPlot->xAxis->setSubTicks(false);
    ui->customPlot->xAxis->setTickLength(0, 4);
    ui->customPlot->xAxis->setRange(0, 5);
    ui->customPlot->xAxis->setBasePen(QPen(Qt::white));
    ui->customPlot->xAxis->setTickPen(QPen(Qt::white));
    ui->customPlot->xAxis->grid()->setVisible(true);
    ui->customPlot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    ui->customPlot->xAxis->setTickLabelColor(Qt::white);
    ui->customPlot->xAxis->setLabelColor(Qt::white);

    // prepare y axis:
    ui->customPlot->yAxis->setRange(0, 12.1);
    ui->customPlot->yAxis->setPadding(5); // a bit more space to the left border
    ui->customPlot->yAxis->setLabel("Bölgelere göre\nrapor sayısı");
    ui->customPlot->yAxis->setBasePen(QPen(Qt::white));
    ui->customPlot->yAxis->setTickPen(QPen(Qt::white));
    ui->customPlot->yAxis->setSubTickPen(QPen(Qt::white));
    ui->customPlot->yAxis->grid()->setSubGridVisible(true);
    ui->customPlot->yAxis->setTickLabelColor(Qt::white);
    ui->customPlot->yAxis->setLabelColor(Qt::white);
    ui->customPlot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
    ui->customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

    // Add data:
    QVector<double> raportNumberData; //nuclearData, regenData;
    raportNumberData  << raportNumberByArea[0] << raportNumberByArea[1] << raportNumberByArea[2] << raportNumberByArea[3];
    //nuclearData << 0.08*10.5 << 0.12*5.5 << 0.12*5.5 << 0.40*5.8 << 0.09*5.2 << 0.00*4.2 << 0.07*11.2;
    //regenData   << 0.06*10.5 << 0.05*5.5 << 0.04*5.5 << 0.06*5.8 << 0.02*5.2 << 0.07*4.2 << 0.25*11.2;
    raportNumber->setData(ticks, raportNumberData);
    //nuclear->setData(ticks, nuclearData);
    //regen->setData(ticks, regenData);

    // setup legend:
    ui->customPlot->legend->setVisible(true);
    ui->customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
    ui->customPlot->legend->setBrush(QColor(255, 255, 255, 100));
    ui->customPlot->legend->setBorderPen(Qt::NoPen);
    QFont legendFont = font();
    legendFont.setPointSize(10);
    ui->customPlot->legend->setFont(legendFont);
    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}

void BolgeEkle::createDateGraph() {
    // set locale to english, so we get english month names:
    ui->customPlot->setLocale(QLocale(QLocale::Turkish));
    // seconds of current time, we'll use it as starting point in time for data:
    double now = QDateTime::currentDateTime().toTime_t();
    srand(8); // set the random seed, so we always get the same random data
    // create multiple graphs:
    for (int gi=0; gi<4; ++gi)
    {
      ui->customPlot->addGraph();
      QColor color(20+200/4.0*gi,70*(1.6-gi/4.0), 150, 150);
      ui->customPlot->graph()->setName(QString::fromStdString("Bölge " + to_string(gi + 1)));
      ui->customPlot->graph()->setLineStyle(QCPGraph::lsLine);
      ui->customPlot->graph()->setPen(QPen(color.lighter(200)));
      ui->customPlot->graph()->setBrush(QBrush(color));
      // generate random walk data:
      QVector<QCPGraphData> timeData(250);
      for (int i=0; i<250; ++i)
      {
        timeData[i].key = now - 24*3600*i;
        timeData[i].value = rand() % 50;
      }
      ui->customPlot->graph()->data()->set(timeData);
    }
    // configure bottom axis to show date instead of number:
    QSharedPointer<QCPAxisTickerDateTime> dateTicker(new QCPAxisTickerDateTime);
    dateTicker->setDateTimeFormat("d. MMMM\nyyyy");
    ui->customPlot->xAxis->setTicker(dateTicker);
    // configure left axis text labels:
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTick(10, "düşük\nseviye");
    textTicker->addTick(50, "yüksek\nseviye");
    ui->customPlot->yAxis->setTicker(textTicker);

    // set a more compact font size for bottom and left axis tick labels:
    ui->customPlot->xAxis->setTickLabelFont(QFont(QFont().family(), 8));
    ui->customPlot->yAxis->setTickLabelFont(QFont(QFont().family(), 8));
    // set axis labels:
    ui->customPlot->xAxis->setLabel("Tarih");
    ui->customPlot->yAxis->setLabel("Tespit edilen kuraldışı durum sayısı.");
    // make top and right axes visible but without ticks and labels:
    ui->customPlot->xAxis2->setVisible(true);
    ui->customPlot->yAxis2->setVisible(true);
    ui->customPlot->xAxis2->setTicks(false);
    ui->customPlot->yAxis2->setTicks(false);
    ui->customPlot->xAxis2->setTickLabels(false);
    ui->customPlot->yAxis2->setTickLabels(false);
    // set axis ranges to show all data:
    ui->customPlot->xAxis->setRange(now-24*3600*249, now);
    ui->customPlot->yAxis->setRange(0, 60);
    // show legend with slightly transparent background brush:
    ui->customPlot->legend->setVisible(true);
    ui->customPlot->legend->setBrush(QColor(255, 255, 255, 150));
}

void BolgeEkle::setRaportNumberByArea()
{
    for (uint64_t i = 0; i < this->raports.size(); ++i) {
        if (raports.at(i).getArea().compare("Bölge 1") == 0) {
            ++this->raportNumberByArea[0];
        } else if (raports.at(i).getArea().compare("Bölge 2") == 0) {
            ++this->raportNumberByArea[1];
        } else if (raports.at(i).getArea().compare("Bölge 3") == 0) {
            ++this->raportNumberByArea[2];
        } else {
            ++this->raportNumberByArea[3];
        }
    }
}

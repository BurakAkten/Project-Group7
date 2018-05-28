#include "graphs.h"
#include "ui_graphs.h"

#include <string>
#include <iostream>

#include "QMessageBox"
#include "QString"
#include "QDebug"

using namespace std;

Graphs::Graphs(QWidget *parent, vector<int> areaCounts) :
    QDialog(parent),
    ui(new Ui::Graphs)
{
    ui->setupUi(this);
    Graphs::createAreaGraph(areaCounts);
}

Graphs::Graphs(QWidget *parent, map<string, int> dateByAreas) :
    QDialog(parent),
    ui(new Ui::Graphs)
{
    ui->setupUi(this);
    Graphs::createDateGraph(dateByAreas);
}

Graphs::~Graphs()
{
    delete ui;
}

void Graphs::createAreaGraph(vector<int> areaCounts) {
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
    ui->customPlot->xAxis->setRange(0, 5); // Bölge sayısı
    ui->customPlot->xAxis->setBasePen(QPen(Qt::white));
    ui->customPlot->xAxis->setTickPen(QPen(Qt::white));
    ui->customPlot->xAxis->grid()->setVisible(true);
    ui->customPlot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    ui->customPlot->xAxis->setTickLabelColor(Qt::white);
    ui->customPlot->xAxis->setLabelColor(Qt::white);

    // prepare y axis:
    ui->customPlot->yAxis->setRange(0, 300); // y eksen sınırları
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
    raportNumberData  << areaCounts[0] << areaCounts[1] << areaCounts[2] << areaCounts[3];
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

void Graphs::createDateGraph(map<string, int> dateByAreas) {
 /*   // set locale to english, so we get english month names:
    ui->customPlot->setLocale(QLocale(QLocale::Turkish));
    // seconds of current time, we'll use it as starting point in time for data:
    QDateTime currentDate = QDateTime::currentDateTime();
    double now = currentDate.toTime_t();
    // create multiple graphs:
    for (int gi=1; gi<4; ++gi)
    {
      ui->customPlot->addGraph();
      QColor color(20+200/4.0*gi,70*(1.6-gi/4.0), 150, 150);
      ui->customPlot->graph()->setName(QString::fromStdString("Bölge " + to_string(gi)));
      ui->customPlot->graph()->setLineStyle(QCPGraph::lsLine);
      ui->customPlot->graph()->setPen(QPen(color.lighter(200)));
      ui->customPlot->graph()->setBrush(QBrush(color));
      // generate random walk data:
      QVector<QCPGraphData> timeData(150);
      int index;
      int lastIndex = 0;
      int cumul = 2;
      auto iter = dateByAreas.rbegin();
      bool isFirst = true;
      while (iter != dateByAreas.rend()) {
          QString date_string_on_db = QString::fromStdString(iter->first);
          QDateTime Date = QDateTime::fromString(date_string_on_db,"yyyy-MM-dd hh:mm:ss");
          index = Date.daysTo(currentDate);
          if (isFirst) {
              isFirst = false;
              lastIndex = index;
          }
          timeData[index].key = now + 24*3600*index;
          if (iter->second == gi) {
              if (index == lastIndex) {
                  cumul += 2;
              } else {
                  timeData[lastIndex].value = cumul;
                  for (int i = lastIndex + 1; i < index; ++i) {
                      timeData[index].key = now + 24*3600*i;
                      timeData[i].value = 0;
                  }
                  //cout << "gi: " << gi << " index: " << index << " lastIndex: " << lastIndex << " cumul: " << cumul << " key: " << timeData[lastIndex].key << " val: " << timeData[lastIndex].value << endl;
                  lastIndex = index;
                  cumul = 2;
              }
          } else {
              timeData[index].value = 0;
          }
          ++iter;
      }
      for (int i = 0; i < 150; ++i)
          cout << "gi: " << gi << " k: " << timeData[i].key << " v: " << timeData[i].value << endl;
      ui->customPlot->graph()->data()->set(timeData);
    }
    // configure bottom axis to show date instead of number:
    QSharedPointer<QCPAxisTickerDateTime> dateTicker(new QCPAxisTickerDateTime);
    dateTicker->setDateTimeFormat("d. MMMM\nyyyy");
    ui->customPlot->xAxis->setTicker(dateTicker);
    // configure left axis text labels:
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    for (int i = 1; i < 21; ++i) {
        textTicker->addTick(i, QString::fromStdString(to_string(i)));
    }
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
    ui->customPlot->xAxis->setRange(now-24*3600*149, now);
    ui->customPlot->yAxis->setRange(0, 20);
    // show legend with slightly transparent background brush:
    ui->customPlot->legend->setVisible(true);
    ui->customPlot->legend->setBrush(QColor(255, 255, 255, 150));*/



    QVector<double> datax = QVector<double>();
    QVector<double> datay1 = QVector<double>();
    QVector<double> datay2 = QVector<double>();

    QTextStream out(stdout);

    auto iter = dateByAreas.rbegin();
    bool isFirst = true;
    QString date_string_on_db, date;
    QStringList pieces;
    QMap<double, int*> map = QMap<double, int*>();
    QDateTime dateT;
    QVector<QString> dates;
    int max=0;
    while (iter != dateByAreas.rend()) {
        date_string_on_db = QString::fromStdString(iter->first);

        pieces = date_string_on_db.split("-");
        date = pieces.value(0)+pieces.value(1); // yıl ve ay olarak split
       // dateT = QDateTime::fromString(data, "yyyy-MM").toTime_t();

        if(!datax.contains(date.toDouble())){
            datax.push_back(date.toDouble());
            dates.push_back(pieces.value(0)+"-"+pieces.value(1));
        }

        if(!map.keys().contains(date.toDouble()))
        {
            int arr[2]; arr[0]=0; arr[1]=0;
            map.insert(date.toDouble(), arr);
        }

        int* tempArr;
        if(iter->second == 0)
        {
            tempArr = map.value(date.toDouble());
            ++tempArr[0];
        }
        else if(iter->second == 1)
        {
            tempArr = map.value(date.toDouble());
            ++tempArr[1];
        }
        ++iter;
    }
    int *tempArr;
    foreach (double var, datax) {
        tempArr = map.value(var);
        if(tempArr[0] > max)
            max = tempArr[0];
        if(tempArr[1] > max)
            max = tempArr[1];
        datay1.push_back(tempArr[0]);
        datay2.push_back(tempArr[1]);

    }

/*
    int i, j;
    double key;
    for (i = 1; i < datax.size(); i++)
    {
       key = datax.at(i);
       j = i-1;

       while (j >= 0 && datax.at(j) > key)
       {
           datax[j+1].value = datax.at(j);
           j = j-1;
       }
       datax[j+1].value = key;
    }*/

    QCPBarsGroup *group = new QCPBarsGroup(ui->customPlot);
    QCPBars *bars;

    out << datax.at(0) << datax.at(1) << datax.at(2) <<"  " << datay1.size() <<  "  " << datay2.size() << endl;

    datax  = QVector<double>() << 1 << 2 << 3 << 4 << 5 << 6;
    datay1 = QVector<double>() << 2 << 3 << 4 << 1 << 2 << 3;
    //datay2 = QVector<double>() << 1 << 2 << 3 << 4 << 5 << 2;


    bars = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
    //ui->customPlot->addPlottable(bars);
    bars->setData(datax, datay1);
    bars->setBrush(QColor(0, 0, 255, 50));
    bars->setPen(QColor(0, 0, 255));
    bars->setWidth(0.15);
    bars->setBarsGroup(group);
    bars = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
    //ui->customPlot->addPlottable(bars);
    bars->setData(datax, datay2);
    bars->setBrush(QColor(180, 00, 120, 50));
    bars->setPen(QColor(180, 00, 120));
    bars->setWidth(0.15);
    bars->setBarsGroup(group);


/*
    QSharedPointer<QCPAxisTickerDateTime> dateTicker(new QCPAxisTickerDateTime);
    dateTicker->setDateTimeFormat("yyyy\nMMMM");


    ui->customPlot->xAxis->setTicker(dateTicker);
*/
    string Months[]={"Ocak","Şubat","Mart","Nisan","Mayıs","Haziran","Temmuz","Ağustos","Eylül","Ekim","Kasım","Aralık"};
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->setTickOrigin(1);
    int i=1;
    foreach (QString var, dates) {
        pieces = var.split("-");
        QString month = pieces.value(1);
        textTicker->addTick(i,  QString::fromStdString(Months[month.toInt()-1]) +"\n"+pieces.value(0));
        out << month << endl;
        ++i;
    }
    out << i << endl;
    ui->customPlot->xAxis->setTicker(textTicker);


    ui->customPlot->xAxis->setLabel("Tarih");
    ui->customPlot->yAxis->setLabel("Yakalanan resim sayıs");

   // ui->customPlot->xAxis->setRange(0, datax.length());
    ui->customPlot->yAxis->setRange(0, max );

  //  ui->customPlot->yAxis->setRange(0, 0.7);
    //ui->customPlot->xAxis->setAutoTickStep(false);
    //ui->customPlot->xAxis->setTickStep(1);
}

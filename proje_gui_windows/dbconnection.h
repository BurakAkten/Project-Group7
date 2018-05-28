#ifndef DBCONNECTION_H
#define DBCONNECTION_H

#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#include <sstream>

#include <QtSql>

#include "region.h"
#include "Client/MatConverter.h"

using namespace std;

class DbConnection {
    QSqlDatabase db;
public:
    DbConnection();
    ~DbConnection();

    QSqlQuery getLastFiftyRaport();
    vector<int> getCountByArea();
    map<string, int> getDateByArea();
    void postReport(int areaId, Mat &image);
    QImage getImage(int id);
};

#endif // DBCONNECTION_H

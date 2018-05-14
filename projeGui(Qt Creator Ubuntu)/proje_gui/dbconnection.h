#ifndef DBCONNECTION_H
#define DBCONNECTION_H

#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#include <sstream>

#include "region.h"
#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

using namespace std;

class DbConnection
{
    sql::Driver *driver;
    sql::Connection *con;
    sql::Statement *stmt;
    sql::ResultSet *res;
public:
    DbConnection();
    ~DbConnection();

    sql::ResultSet *getLastFiftyRaport();
    vector<int> getCountByArea();
    map<string, int> getDateByArea();
    sql::ResultSet *getAllAreas();
    void updateArea(Region region);
};

#endif // DBCONNECTION_H

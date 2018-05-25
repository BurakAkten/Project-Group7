#ifndef DBCONNECTION_H
#define DBCONNECTION_H

#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#include <sstream>

#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"

using namespace std;
using namespace cv;

class DbConnection
{
    sql::Driver *driver;
    sql::Connection *con;
    sql::Statement *stmt;
    sql::ResultSet *res;
public:
    DbConnection();
    ~DbConnection();

    void push(const Mat& frame, int areaID);
};

#endif // DBCONNECTION_H

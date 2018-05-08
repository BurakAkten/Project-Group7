#ifndef DBCONNECTION_H
#define DBCONNECTION_H

#include <cstdlib>
#include <iostream>

#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

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
};

#endif // DBCONNECTION_H

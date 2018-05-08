#include "dbconnection.h"

DbConnection::DbConnection()
{
    driver = get_driver_instance();
    con = driver->connect("proje7.mysql.database.azure.com", "projeadmin@proje7", "Proje123");
    /* Connect to the MySQL test database */
    con->setSchema("test");
}

DbConnection::~DbConnection()
{
    delete res;
    delete stmt;
    delete con;
}

sql::ResultSet *DbConnection::getLastFiftyRaport()
{
    stmt = con->createStatement();
    return stmt->executeQuery("SELECT * FROM test.criticalareas ORDER BY id DESC LIMIT 50;");
}

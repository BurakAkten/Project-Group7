#include "dbconnection.h"

DbConnection::DbConnection() {
    driver = get_driver_instance();
    con = driver->connect("proje7.mysql.database.azure.com", "projeadmin@proje7", "Proje123");
    /* Connect to the MySQL test database */
    con->setSchema("test");
}

DbConnection::~DbConnection() {
    delete res;
    delete stmt;
    delete con;
}

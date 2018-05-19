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

sql::ResultSet *DbConnection::getLastFiftyRaport() {
    stmt = con->createStatement();
    return stmt->executeQuery("SELECT * FROM test.reports ORDER BY date DESC LIMIT 50;");
}

vector<int> DbConnection::getCountByArea() {
    vector<int> areaCounts;
    stmt = con->createStatement();
    for (int i = 1; i < 5; ++i){
        std::stringstream ss;
        ss << "SELECT * FROM test.reports WHERE areaid=" << i << " LIMIT 300;";
        sql::ResultSet *res = stmt->executeQuery(ss.str());
        areaCounts.push_back(res->rowsCount());
    }
    return areaCounts;
}

map<string, int> DbConnection::getDateByArea() {
    map<string, int> dateByAreas;
    res = con->createStatement()->executeQuery("SELECT date, areaid FROM test.reports ORDER BY date DESC LIMIT 500;");
    while (res->next()) {
        dateByAreas[res->getString(1)] = res->getInt(2);
    }
    return dateByAreas;
}

sql::ResultSet *DbConnection::getAllAreas() {
    stmt = con->createStatement();
    return stmt->executeQuery("SELECT * FROM test.areas ORDER BY id;");
}

void DbConnection::updateArea(Region region) {
    try {
        std::stringstream ss;
        ss << "UPDATE test.areas SET x1=" << region.x1 << ", x2=" << region.x2 << ", y="
           << region.y << " WHERE id=" << region.name.substr(region.name.size() - 1) << ";";
        con->createStatement()->executeQuery(ss.str());
    } catch (sql::SQLException e) {
        std::cout << e.what();
    }
}

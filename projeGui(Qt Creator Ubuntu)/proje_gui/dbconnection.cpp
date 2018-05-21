#include "dbconnection.h"
#include "Client/MatConverter.h"

using namespace server_client;

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
    delete pstmt;
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
    res = con->createStatement()->executeQuery("SELECT date, areaid FROM test.reports ORDER BY date LIMIT 500;");
    while (res->next()) {
        dateByAreas[res->getString(1)] = res->getInt(2);
    }
    return dateByAreas;
}

void DbConnection::postReport(int areaId) {
    try {
        stmt = con->createStatement();
        stringstream ss;
        ss << "INSERT INTO test.reports (id, areaid, date) VALUES(0, " << areaId << ", NOW());";
        stmt->executeQuery(ss.str());
    } catch(sql::SQLException e) {
        cerr << e.what() << endl;
    }
}

void DbConnection::postImage(Mat &image) {
    try {
        MatConverter converter;
        vector<byte> newVec = converter.byteStream(image);
        std::string stringN(newVec.begin(), newVec.end());
        std::istringstream str(stringN);
        pstmt = con->prepareStatement("INSERT INTO image_test(id, image) VALUES (0, ?)");
        pstmt->setBlob( 1, &str);
        pstmt->executeUpdate();
    } catch(sql::SQLException e) {
        cerr << e.what() << endl;
    }
}

cv::Mat DbConnection::getImage(int id) {
    stmt = con->createStatement();
    stringstream ss;
    ss << "SELECT * FROM test.image_test WHERE id=" << id <<  ";";
    res = stmt->executeQuery(ss.str());
    std::istream *is;

    while(res->next()){
        is = res->getBlob(1);
    }

    byte buf[100000];
    int len=sizeof( buf );
    std::size_t n = 0;

    while( len > 0 && is->good() ) {
        is->read( (char *) &buf[n], len );
        int i = is->gcount();
        n += i;
        len -= i;
    }
    vector<byte> v;
    for(int i=0;i<len;++i){
        byte b = buf[i];
        v.push_back(b);
        cout<<v.at(i);
    }
    MatConverter converter;
    Mat mat = converter.makeMat(v);
    return mat;
}

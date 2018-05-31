#include "dbconnection.h"
#include "Client/MatConverter.h"

using namespace server_client;

struct matInfo {
    matInfo(int _cols = -1, int _rows = -1, int _type = CV_8U) :
            cols(_cols), rows(_rows), type(_type){};
    int cols, rows, type;
    size_t Size() {return CV_ELEM_SIZE(type) * rows * cols;}
    size_t RowSize(){ return CV_ELEM_SIZE(type) * cols; }
};

bool MatSerialize(ostream &out, const Mat& mat) {
    matInfo mi( mat.cols, mat.rows, mat.type() );
    std::ostream::sentry s(out);
    if (!(s && out.good()))
        return false;
    out.write((char*)(&mi), sizeof(matInfo));
    if (mat.isContinuous()) {
        out.write((char*)mat.data, mi.Size());
    } else {
        size_t rowsz = mi.RowSize();
        for (int r = 0; r < mi.rows; ++r)
            out.write((char*)mat.ptr<char>(r), rowsz);
    }
    out.flush();
    return out.good();
}

stringstream& operator<< (stringstream &out, const cv::Mat& mat)  {
    MatSerialize(out, mat);
    return out;
}

bool MatDeserialize(std::istream& in, cv::Mat& mat) {
    std::istream::sentry s(in);
    if (!(s && in.good())) {
        mat = Mat();
        return false;
    }
    matInfo mi;
    in.read((char*)(&mi), sizeof(matInfo));
    if (mi.Size() < 0) {
        mat = Mat();
        return false;
    }
    mat = Mat(mi.rows, mi.cols, mi.type);
    in.read((char*)mat.data, mi.Size());
    return in.good();
}

istream& operator>>(std::istream& in, cv::Mat& mat) {
    MatDeserialize(in, mat);
    return in;
}

DbConnection::DbConnection() {
    driver = get_driver_instance();
    con = driver->connect("localhost", "root", "admin");
    //con = driver->connect("proje7.mysql.database.azure.com", "projeadmin@proje7", "Proje123");
    /* Connect to the MySQL test database */
    con->setSchema("test");
}

DbConnection::~DbConnection() {
    delete con;
}

sql::ResultSet *DbConnection::getLastFiftyRaport() {
    sql::Statement *stmt = con->createStatement();
    sql::ResultSet *res = stmt->executeQuery("SELECT id, areaid, date FROM test.reports ORDER BY date DESC LIMIT 50;");
    delete stmt;
    return res;
}

vector<int> DbConnection::getCountByArea() {
    vector<int> areaCounts;
    sql::Statement *stmt = con->createStatement();
    for (int i = 1; i < 5; ++i){
        std::stringstream ss;
        ss << "SELECT id FROM test.reports WHERE areaid=" << i << " LIMIT 300;";
        sql::ResultSet *res = stmt->executeQuery(ss.str());
        areaCounts.push_back(res->rowsCount());
    }
    delete stmt;
    return areaCounts;
}

map<string, int> DbConnection::getDateByArea() {
    map<string, int> dateByAreas;
    sql::ResultSet *res = con->createStatement()->executeQuery("SELECT date, areaid FROM test.reports ORDER BY date LIMIT 500;");
    while (res->next()) {
        dateByAreas[res->getString(1)] = res->getInt(2);
    }
    return dateByAreas;
}

void DbConnection::postReport(int areaId, Mat &image) {
    try {
        std::stringstream ss;
        ss << image;
        std::istream is(ss.rdbuf());

        sql::PreparedStatement *pstmt;
        pstmt = con->prepareStatement("INSERT INTO test.reports (id, image, areaid, date) VALUES(0, ?, ?, NOW())");
        pstmt->setBlob(1, &is);
        pstmt->setInt(2, areaId);
        pstmt->executeUpdate();
        delete pstmt;
    } catch(sql::SQLException &e) {
        cerr << e.what() << endl;
    }
}

cv::Mat DbConnection::getImage(int id) {
    sql::Statement *stmt;
    stmt = con->createStatement();
    stringstream ss;
    ss << "SELECT image FROM test.reports WHERE id=" << id << ";";
    sql::ResultSet *res = stmt->executeQuery(ss.str());
    Mat frame;
    while (res->next()) {
        istream *os = res->getBlob(1);
        *os >> frame;
    }
    delete stmt;
    return frame;
}

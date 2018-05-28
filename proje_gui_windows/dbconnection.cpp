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
    QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("proje7.mysql.database.azure.com");
    //db.setDatabaseName("flightdb");
    db.setUserName("projeadmin@proje7");
    db.setPassword("Proje123");
    bool ok = db.open();
    if (ok)
        cout << "Connected" << endl;
    else
        cout << "Not connected" << endl;
}

DbConnection::~DbConnection() {
    db.close();
}

QSqlQuery DbConnection::getLastFiftyRaport() {
    QSqlQuery query;
    query.exec("SELECT id, areaid, date FROM test.reports ORDER BY date DESC LIMIT 50");
    return query;
}

vector<int> DbConnection::getCountByArea() {
    vector<int> areaCounts;
    QSqlQuery query;
    for (int i = 1; i < 5; ++i){
        std::stringstream ss;
        ss << "SELECT id FROM test.reports WHERE areaid=" << i << " LIMIT 300;";
        query.exec(QString::fromStdString(ss.str()));
        areaCounts.push_back(query.numRowsAffected());
    }
    return areaCounts;
}

map<string, int> DbConnection::getDateByArea() {
    map<string, int> dateByAreas;
    QSqlQuery query;
    query.exec("SELECT date, areaid FROM test.reports ORDER BY date LIMIT 500");
    while (query.next()) {
        dateByAreas[query.value(0).toString().toStdString()] = query.value(1).toInt();
    }
    return dateByAreas;
}

void DbConnection::postReport(int areaId, Mat &image) {
    QImage qimage = QImage((uchar*) image.data, image.cols, image.rows, image.step, QImage::Format_RGB888);
    QByteArray arr;
    QBuffer buffer(&arr);
    buffer.open(QIODevice::WriteOnly);
    qimage.save(&buffer, "PNG");

    QSqlQuery query;
    query.prepare("INSERT INTO test.reports (id, image, areaid, date) VALUES(0, ?, ?, NOW())");
    query.addBindValue(arr);
    query.addBindValue(areaId);
    query.exec();
}

QImage DbConnection::getImage(int id) {
    stringstream ss;
    ss << "SELECT image FROM test.reports WHERE id=" << id << ";";
    QSqlQuery query;
    query.exec(QString::fromStdString(ss.str()));
    QByteArray outByteArray = query.value( 0 ).toByteArray();
    return QImage::fromData(outByteArray,"PNG");
}

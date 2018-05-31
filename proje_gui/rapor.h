#ifndef RAPOR_H
#define RAPOR_H

#include <ctime>
#include <string>

using namespace std;

class Rapor
{
public:
    explicit Rapor(int id, string area, string t);
    int getId() const;
    void setId(int value);

    string getArea() const;
    void setArea(const string &value);

    string getTime() const;
    void setTime(const string &value);

private:
    int id;
    string area;
    string time;
};

#endif // RAPOR_H

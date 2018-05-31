#include "rapor.h"

Rapor::Rapor(int id, string area, string time)
{
    this->id = id;
    this->area = area;
    this->time = time;
}

int Rapor::getId() const
{
    return id;
}

void Rapor::setId(int value)
{
    id = value;
}

string Rapor::getArea() const
{
    return area;
}

void Rapor::setArea(const string &value)
{
    area = value;
}

string Rapor::getTime() const
{
    return time;
}

void Rapor::setTime(const string &value)
{
    time = value;
}

#ifndef REGION_H
#define REGION_H

#include <QMetaType>

typedef struct Regions
{
    std::string name;
    int x1;
    int x2;
    int y;
}Region;

Q_DECLARE_METATYPE(Region);

#endif // REGION_H

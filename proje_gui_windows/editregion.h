#ifndef EDITREGION_H
#define EDITREGION_H

#include <QDialog>
#include <QFile>
#include "region.h"


namespace Ui {
class EditRegion;
}


class EditRegion : public QDialog
{
    Q_OBJECT

public:
    explicit EditRegion(QWidget *parent = 0);
    explicit EditRegion(QWidget *parent = 0, Region *region=0);
    ~EditRegion();

private slots:
    void on_edit_clicked();

private:
    Ui::EditRegion *ui;
    Region *region;
};

#endif // EDITREGION_H

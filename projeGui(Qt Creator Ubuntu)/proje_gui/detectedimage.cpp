#include "detectedimage.h"
#include "ui_detectedimage.h"

DetectedImage::DetectedImage(QWidget *parent, QImage &image) :
    QDialog(parent),
    ui(new Ui::DetectedImage)
{
    ui->setupUi(this);
    ui->label->setPixmap(QPixmap::fromImage(image));
    ui->label->setScaledContents(true);
    ui->label->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
}

DetectedImage::~DetectedImage()
{
    delete ui;
}

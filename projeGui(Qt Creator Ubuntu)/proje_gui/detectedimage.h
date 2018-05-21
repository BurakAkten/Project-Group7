#ifndef DETECTEDIMAGE_H
#define DETECTEDIMAGE_H

#include <QDialog>

namespace Ui {
class DetectedImage;
}

class DetectedImage : public QDialog
{
    Q_OBJECT

public:
    explicit DetectedImage(QWidget *parent, QImage &image);
    ~DetectedImage();

private:
    Ui::DetectedImage *ui;
};

#endif // DETECTEDIMAGE_H

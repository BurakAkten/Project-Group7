

#ifndef RECOGNATION_H
#define RECOGNATION_H

#include "variables.h"
#include "Detected.h"
#include <iostream>
#include <queue>


using namespace cv;

class Recognation {


public:
    Mat run(Mat cameraFeed);
    ~Recognation();

private:
    Mat cameraFeed;

    Mat ROI; // Region of Interest
    Detected *detectedHelmet;

    Mat criticalRegion(Mat image);

    void trackFilteredObject(std::vector<Mat> src, Mat original, int index);
    void detectBody(Mat frame);

    void alarm();
};


#endif //RECOGNATION_H

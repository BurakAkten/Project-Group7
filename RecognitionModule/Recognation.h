

#ifndef RECOGNATION_H
#define RECOGNATION_H

#include "variables.h"
#include <iostream>
#include <queue>


using namespace cv;

class Recognation {


public:
    int run();

private:
    Mat cameraFeed;
    Mat ROI; // Region of Interest
    Mat rangeOut; // inRange function output
    std::vector<Scalar> colors;

    Mat criticalRegion(Mat image);

    void trackFilteredObject(std::vector<Mat> src, Mat original);
    std::vector<Mat> detectBody(Mat frame);
};


#endif //RECOGNATION_H

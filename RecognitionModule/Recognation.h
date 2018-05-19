

#ifndef RECOGNATION_H
#define RECOGNATION_H

#include "variables.h"
#include "Detected.h"
//#include <wiringPi.h>
#include <iostream>
#include <queue>


using namespace cv;

class Recognation {


public:
    bool run(Mat& cameraFeed, Mat& result);
    void clearNoHelmet();

private:
    Mat ROI; // Region of Interest
    vector<Mat*> noHelmetFrames;

    Mat criticalRegion(Mat image);

    void trackFilteredObject(std::vector<Mat>& src, Mat& original, int index, Detected& detectedHelmet);
    void detectBody(Mat& frame, Detected& detectedHelmet);

    void alarm();
};


#endif //RECOGNATION_H

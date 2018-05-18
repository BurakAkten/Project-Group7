

#ifndef RECOGNATION_H
#define RECOGNATION_H

#include "variables.h"
#include "Detected.h"
#include <wiringPi.h>
#include <stdio.h>
#include <iostream>
#include <queue>
#include <softTone.h>


using namespace cv;

class Recognation {


public:
    bool run(Mat cameraFeed, Mat* result);
    ~Recognation();
    void clearNoHelmet();

private:
    Mat cameraFeed;

    Mat ROI; // Region of Interest
    Detected *detectedHelmet;
    vector<Mat*> noHelmetFrames;

    Mat criticalRegion(Mat image);

    void trackFilteredObject(std::vector<Mat> src, Mat original, int index);
    void detectBody(Mat frame);

    void alarm();
};


#endif //RECOGNATION_H



#ifndef DETECTED_H
#define DETECTED_H


#include "variables.h"

using namespace cv;
using namespace std;

class Detected{

    friend class Recognation;

public:
    Detected(Mat mainFrame);
    void setMainFrame(Mat frame);
    Mat getMainFrame();
    Mat drawRects();
    void draw();
private:
    Mat mainFrame;
protected:
    vector<Mat> detectedFrames;
    vector<Rect> detectedRects;
    vector<Rect> noHemletRects;

};

#endif //DETECTED_H

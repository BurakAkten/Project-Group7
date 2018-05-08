
#include "Detected.h"

Detected::Detected(Mat mainFrame) {
    setMainFrame(mainFrame);
}

void Detected::setMainFrame(Mat frame) {
    this->mainFrame = frame;
}

cv::Mat Detected::getMainFrame() {
    return mainFrame;
}

Mat Detected::drawRects() {
    for(int i = 0; i < noHemletRects.size(); i++){
        rectangle(mainFrame, noHemletRects[i].tl(), noHemletRects[i].br(), drawColor, thickness, lineType);
    }

    return mainFrame;
}

void Detected::draw() {

    for(int i = 0; i < detectedRects.size(); i++){
        rectangle(mainFrame, Point(5, 25), detectedRects[i].br(), (255, 255, 255), 10, lineType);
    }

}



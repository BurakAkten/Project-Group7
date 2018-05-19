
#include "Detected.h"

Detected::Detected(Mat mainFrame) {
    setMainFrame(mainFrame);
}

void Detected::setMainFrame(Mat frame) {
    this->mainFrame = frame;
}

void Detected::drawRects() {
    for(int i = 0; i < noHemletRects.size(); i++){
        rectangle(mainFrame, noHemletRects[i].tl(), noHemletRects[i].br(), drawColor, thickness, lineType);
    }

}

void Detected::draw() {

    for(int i = 0; i < detectedRects.size(); i++){
        rectangle(mainFrame, Point(5, 25), detectedRects[i].br(), (255, 255, 255), 10, lineType);
    }
}





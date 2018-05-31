//
// Created by Şevval on 2.05.2018.
//

#ifndef VARIABLES_H
#define VARIABLES_H

#include <map>
#include "opencv2/opencv.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <vector>

using namespace cv;
using namespace std;

const int ESC = 27;
//const Scalar redLower = Scalar(13, 15, 139);
//const Scalar redUpper = Scalar(85, 61, 210);
const Scalar redLower = Scalar(17, 15, 100);
const Scalar redUpper = Scalar(50, 56, 200);
const Scalar greenLower = Scalar(255, 255, 0);
const Scalar greenUpper = Scalar(255, 255, 150);
const Scalar yellowLower = Scalar(47, 231, 253);
const Scalar yellowUpper = Scalar(26, 211, 231);

const string cascadeUpper = "image/CascadesFiles/cascadeH5.xml";
const Size croppedSize(300,300);
const double scaleFactor = 1.1;
const int minNeighbours = 2;
const int flag = 0 | CV_HAAR_SCALE_IMAGE;
const Size maxSize = Size(600, 600);
const Size minSize = Size(300, 300);

// Variables for draw rectangle
const Scalar drawColor = Scalar(0, 0, 255);
const int thickness = 2;
const int lineType = 8;


const int BuzzerPin = 25;

#endif //VARIABLES_H

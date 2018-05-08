#include "Recognation.h"

using namespace cv;
using namespace std;

Mat Recognation::run(Mat cameraFeed){

    // Call constructor
    detectedHelmet = new Detected(cameraFeed);

    // Critical Region Operations
    ROI = criticalRegion(cameraFeed);

    // Detect upper body
    detectBody(ROI);
    vector<Mat> sendTracking;

    Mat redOut, greenOut, yellowOut;

    if( !detectedHelmet->detectedFrames.empty() ) {

        for(int i = 0; i < detectedHelmet->detectedFrames.size(); i+=1 ){

            Mat cutTheDetected;
            detectedHelmet->detectedFrames.at(i).copyTo(cutTheDetected);
            resize(cutTheDetected, cutTheDetected, Size(cutTheDetected.cols, cutTheDetected.rows - 20));
//            Mat cpy;
//            cvtColor(cameraFeed, cpy, COLOR_BGR2HSV);
//            Mat1b mask1, mask2;
//            inRange(cpy, Scalar(0, 70, 50), Scalar(10, 255, 255), mask1);
//            inRange(cpy, Scalar(170, 70, 50), Scalar(180, 255, 255), mask2);
//
//            Mat1b redOut = mask1 | mask2;

            // Find red helmet
//            inRange(detectedHelmet->detectedFrames.at(i), redLower, redUpper, redOut);
            inRange(cutTheDetected, redLower, redUpper, redOut);
            sendTracking.push_back(redOut);

//            // Find green helmet
//            inRange(detectedHelmet->detectedFrames.at(i), greenLower, greenUpper, greenOut);
//            sendTracking.push_back(greenOut);
//
//            // Find yellow helmet
//            inRange(detectedHelmet->detectedFrames.at(i), yellowLower, yellowUpper, yellowOut);
//            sendTracking.push_back(yellowOut);

            trackFilteredObject(sendTracking, cameraFeed, i);
            sendTracking.clear();
        }

    }

    // Draw function
    detectedHelmet->draw();
    return detectedHelmet->drawRects();

}

Mat Recognation::criticalRegion(Mat image) {
    // Critical region operations
    // All pixel that out of critical region mark as 0.
    return image;
}

void Recognation::trackFilteredObject(vector<Mat> frames, Mat original, int index) {

    for (size_t i = 0; i < frames.size(); i++)
    {
        // Find contours elements
        vector< vector<Point> > contours;
        vector<Vec4i> hierarchy;

        // Decrease the noise
        blur(frames[i], frames[i], Size(5, 5));

        //find contours of filtered image using openCV findContours function
        findContours(frames[i], contours, hierarchy, CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE);

        int numOfDetected = static_cast<int>(contours.size());
        double maxArea = 0;
        int required;


        if (numOfDetected < 500 && numOfDetected != 0) {

            // Find the contours that has largest area
            for (int index = 0; index >= 0; index = hierarchy[index][0]) {

                Moments moment = moments((cv::Mat)contours[index]);
                double area = moment.m00;

                if (area > maxArea) {
                    maxArea = area;
                    required = index;
                }

            }

            // Get bounding rectangle
            vector<Point> contours_points;
            // Approximates a polygonal curve with the specified precision
            approxPolyDP(Mat(contours[required]), contours_points, 3, true);
            // Calculate the up-right bounding rectangle of a point set
            Rect boundRect = boundingRect(Mat(contours_points));


            // Draw contours
//             drawContours(original, contours, required, (0,0,0), 1);

            // rectangle(original, boundRect.tl(), boundRect.br(), colors[i], 2, 8, 0);

        }
        else {
            // There is no helmet
            Rect noHelmet = detectedHelmet->detectedRects.at(index);
            detectedHelmet->noHemletRects.push_back(noHelmet);
        }

    }
}

void Recognation::detectBody(Mat frame) {

    // prepare cascadeClassifier
    CascadeClassifier detectorUpper;

    // Load cascade into CascadeClassifier
    bool loaded1 = detectorUpper.load(cascadeUpper);
    if (!loaded1) { cout << "Error loading upper body cascade file\n" << endl; exit(1); };

    vector<Rect> detectedHeads;
    Mat img, crp;

    frame.copyTo(img);

    // color to gray image
    cvtColor(img, img, CV_BGR2GRAY);
    equalizeHist(img, img);

    // detect people
    detectorUpper.detectMultiScale(img, detectedHeads, scaleFactor, minNeighbours, flag, minSize, maxSize);
    Rect head;

    detectedHelmet->detectedRects = detectedHeads;

    // Draw results from detectorUpper into original colored image
    if ( !detectedHeads.empty() ) {
        for (int gg = 0; gg < detectedHeads.size(); gg++) {

            head = detectedHeads[gg];

            crp = frame(head);
            resize(crp, crp, croppedSize);

            detectedHelmet->detectedFrames.push_back(crp);

        }
    }

}

void Recognation::alarm() {
    /*Bu fonksiyonda buzzer çalıştırılacak */
    cout << "buzzer" << endl;

}

Recognation::~Recognation() {
    free(detectedHelmet);

}

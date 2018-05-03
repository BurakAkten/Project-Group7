#include "Recognation.h"

using namespace cv;
using namespace std;

int Recognation::run(){

    // Some beginning operation


    colors.push_back(Scalar(0, 0, 255));//red
    colors.push_back(Scalar(0, 128, 0));//green
    colors.push_back(Scalar(0, 255, 255));//yellow

//     Video capture object to acquire webcam feed
    VideoCapture capture;
    capture.open(0);

    while(true){

        // Take frame
        capture >> cameraFeed;


        // Critical Region Operations
        ROI = criticalRegion(cameraFeed);

        // Detect upper body
        vector<Mat> cropped = detectBody(ROI);
        vector<Mat> sendTracking;

        if( !cropped.empty() ) {
            for(int i = 0; i < cropped.size(); i+=1 ){
                // Find red helmet
                inRange(cropped[i], redLower, redUpper, rangeOut);
                sendTracking.push_back(rangeOut);

//                // Find green helmet
//                inRange(cropped[i], greenLower, greenUpper, rangeOut);
//                sendTracking.push_back(rangeOut);
//
//                // Find yellow helmet
//                inRange(cropped[i], yellowLower, yellowUpper, rangeOut);
//                sendTracking.push_back(rangeOut);
                trackFilteredObject(sendTracking, cropped[i]);
            }
        }
        else{
            cout << "There is not people" << endl;

        }
    }
}

Mat Recognation::criticalRegion(Mat image) {
    // Critical region operations
    // All pixel that out of critical region mark as 0.
    return image;
}

void Recognation::trackFilteredObject(vector<Mat> src, Mat original) {

    for (size_t i = 0; i < src.size(); i++)
    {
        vector< vector<Point> > contours;
        vector<Vec4i> hierarchy;
        blur(src[i], src[i], Size(5, 5));

        string winName = "Jamesten gelen_" + i;
        imshow(winName.c_str(), src[i]);
        waitKey(0);
        //find contours of filtered image using openCV findContours function
        findContours(src[i], contours, hierarchy, CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE);

        int numOfDetected = static_cast<int>(contours.size());
        double maxArea = 0;
        int required;


        if (numOfDetected < 500 && numOfDetected != 0) { //?  gürültü sayısı denebilir. Ne kadar büyük olursa o kadar hassas bir tarama yaparsın ama döngü o kadar çok döneceği için o kadar da yavaş olur

            // Find the contours that has largest area
            for (int index = 0; index >= 0; index = hierarchy[index][0]) {//?
                Moments moment = moments((cv::Mat)contours[index]);//? yükseltilerin çevrelediğ alan
                double area = moment.m00; //m00 tam olarak bu alanı veriyor


                /*drawContours(original, contours, index, (0, 0, 0), 2);

                vector<Point> contours_points;
                // Approximates a polygonal curve with the specified precision
                approxPolyDP(Mat(contours[index]), contours_points, 3, true);
                // Calculate the up-right bounding rectangle of a point set
                Rect boundRect = boundingRect(Mat(contours_points));

                rectangle(original, boundRect.tl(), boundRect.br(), Scalar(0, 0, 0), 2, 8, 0);*/

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
            //drawContours(original, contours, required, (0,0,0), 1);

            rectangle(original, boundRect.tl(), boundRect.br(), colors[i], 2, 8, 0);
//            double distance = 0;
//
//            distance = 8414.7*pow(boundRect.area(), -0.468);//?
//            cout << distance << " cm." << endl;
//
//            stringstream ss;
//            ss << "Distance : ";
//            ss << distance;
//            ss << " cm.";
//            String dis = ss.str();
//            putText(original, dis, Point(50, 50), CV_FONT_HERSHEY_COMPLEX, 1, Scalar(0, 0, 0));
            imshow("Last", original);
            waitKey(0);
        }
        else {
            // TODO : HAta
            cout << "There is not helmet" << endl;
        }

        imshow("Last", original);
        waitKey(0);
    }
}

std::vector<Mat> Recognation::detectBody(Mat frame) {
    // prepare cascadeClassifier
    CascadeClassifier detectorUpper;
    //cropped images vector
    vector<Mat> cropped;

    //Haarcascade_mcs_upperbody gives more precision than the other.
    string cascadeUpper = "CascadesFiles/haarcascade_upperbody.xml";
    // Load cascade into CascadeClassifier
    bool loaded1 = detectorUpper.load(cascadeUpper);
    if (!loaded1) { cout << "Error loading upper body cascade file\n" << endl; return cropped; };

    vector<Rect> upperBody;
    Mat img;
    Mat crp;
    Size size(300,300);


    frame.copyTo(img);
    // color to gray image
    cvtColor(img, img, CV_BGR2GRAY);
    equalizeHist(img, img);

    // detect people
    detectorUpper.detectMultiScale(img,upperBody, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE, Size(100, 100));
    Rect upper;

    // Draw results from detectorUpper into original colored image
    if (upperBody.size() > 0) {
        for (int gg = 0; gg < upperBody.size(); gg++) {

            rectangle(frame, upperBody[gg].tl(), upperBody[gg].br(), Scalar(0, 255, 0), 2, 8, 0);
            upper=upperBody[gg];


            //230*280
            crp = frame(upper);
            resize(crp,crp,size);
            // inRange(crp, Scalar(48, 37,139), Scalar(43,33,124), crp);
            cropped.push_back(crp);

        }
    }

    namedWindow("UpperBody sonucu", WINDOW_AUTOSIZE);
    imshow("UpperBody sonucu", frame);
    waitKey(0);
    return cropped;
}

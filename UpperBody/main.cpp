#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/objdetect/objdetect.hpp"
#include <vector>
#include <iostream>

using namespace cv;
using namespace std;


//UpperBody detection.
vector<Mat> detectUpper(Mat frame);


int main(int argc, const char** argv){

    //video input from webcam
    VideoCapture cap(0);
    //VideoCapture csa(0);
    Mat frame;
    Mat crop;
    Mat output1;

    // Basic video input loop
    for (;;){
        cap >> frame;
        vector<Mat> vec_of_cropped;
       if (!frame.empty()){

          vec_of_cropped = detectUpper(frame);
          cout<<vec_of_cropped.size()<<endl;


        }

        else{
            cout << "No captured frame. Stopping!" << endl;
            break;
        }
        for(int i = 0; i < vec_of_cropped.size(); ++i){
           Mat output;
          namedWindow("crop", WINDOW_AUTOSIZE);
            imshow("crop", vec_of_cropped[i]);
            inRange(vec_of_cropped[i], Scalar(13, 15, 139), Scalar(85,56,210), output);
            //trackFilteredObject(output,output1);
            namedWindow("inrange", WINDOW_AUTOSIZE);
            imshow("inrange", output);

        }

        //terminating if esc pressed
        int key1 = waitKey(20);
        if ((char)key1 == 27) { break; }
    }
    return 1;
}


vector<Mat> detectUpper(Mat frame){

    // prepare cascadeClassifier
    CascadeClassifier detectorUpper;
    //cropped images vector
    vector<Mat> cropped;
    //!!Put your cascade or opencv cascede into project folder !!
    //Haarcascade_mcs_upperbody gives more precision than the other.
    string cascadeUpper = "CascadesFiles/haarcascade_mcs_upperbody.xml";
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
    // draw results
   namedWindow("prew", WINDOW_AUTOSIZE);
    imshow("prew", frame);

    return cropped;
}
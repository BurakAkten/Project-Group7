#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/objdetect/objdetect.hpp"
#include <vector>
#include <iostream>

using namespace cv;
using namespace std;


// Face detection
void detectUpper(Mat frame);


int main(int argc, const char** argv){

	// prepare video input
	VideoCapture cap(0);
	Mat frame;
	

	// Basic video input loop
	for (;;){
		cap >> frame;
		if (!frame.empty()) {
			detectUpper(frame);
		}

		else{
			cout << "No captured frame. Stopping!" << endl;
			break;
		}
			//terminating if esc pressed
			int key1 = waitKey(20);
			if ((char)key1 == 27) { break; }

	}
	return 1;
}


void detectUpper(Mat frame) {

	// prepare cascadeClassifier
	CascadeClassifier detectorUpper;
	// !! Put your cascade or opencv cascede into project folder !!
	string cascadeUpper = "CascadeFiles/cascadeH5.xml";
	// Load cascade into CascadeClassifier
	bool loaded1 = detectorUpper.load(cascadeUpper);
	if (!loaded1) { cout << "Error loading upper body cascade file\n" << endl; return; };
	
	vector<Rect> upperBody;
	Mat img;


	frame.copyTo(img);
	// color to gray image
	cvtColor(img, img, CV_BGR2GRAY);
	equalizeHist(img, img);

	// detect people, more remarks in performace section  
	detectorUpper.detectMultiScale(img, upperBody, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE, Size(100, 100));

	// Draw results from detectorUpper into original colored image
	if (upperBody.size() > 0) {
		for (int gg = 0; gg < upperBody.size(); gg++) {

			rectangle(frame, upperBody[gg].tl(), upperBody[gg].br(), Scalar(0, 255, 0), 2, 8, 0);

		}
	}
	// draw results
	namedWindow("prew", WINDOW_AUTOSIZE);
	imshow("prew", frame);

	return;
}

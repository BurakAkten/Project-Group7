#include "opencv2\highgui.hpp"
#include "opencv2\imgproc.hpp"
#include "opencv2\objdetect\objdetect.hpp"
#include "opencv2/video/tracking.hpp"
#include <vector>
#include <stdio.h>
#include <Windows.h>//if not in windows might want to edit this
#include <iostream>
#include <time.h>
#include <ctime>

using namespace cv;
using namespace std;



int main(int argc, const char** argv){


	// prepare video input
	VideoCapture cap(0);


	// prepare cascadeClassifier
	CascadeClassifier detectorUpper;
	// !! Put your cascade or opencv cascede into project folder !!
	string cascadeUpper = "CascadeFiles/cascadeH5.xml";
	// Load cascade into CascadeClassifier
	bool loaded1 = detectorUpper.load(cascadeUpper);
	if (!loaded1){ cout << "Error loading upper body cascade file\n" << endl; return 0; };


	// Basic video input loop
	for (;;)
	{

		bool Is = cap.grab();
		if (Is == false) {

			cout << "Video Capture Fail" << endl;
			break;
		}
		else {
			// Just for measure time   
			const clock_t begin_time = clock();

			// Store results for upperbody
			vector<Rect> upperBody;

			// prepare 2 Mat container
			Mat img;
			Mat original;

			// capture frame from video file
			cap.retrieve(img, CV_CAP_OPENNI_BGR_IMAGE);
			// Resize image if you want with same size as your VideoWriter
			resize(img, img, Size(640, 480));
			// Store original colored image
			img.copyTo(original);
			// color to gray image
			cvtColor(img, img, CV_BGR2GRAY);
			equalizeHist(img, img);

			// detect people, more remarks in performace section  
			detectorUpper.detectMultiScale(img, upperBody, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE, Size(100, 100));


		

			// Draw results from detectorUpper into original colored image
			if (upperBody.size() > 0) {
				for (int gg = 0; gg < upperBody.size(); gg++) {

					rectangle(original, upperBody[gg].tl(), upperBody[gg].br(), Scalar(0, 255, 0), 2, 8, 0);

				}
			}
			// draw results
			namedWindow("prew", WINDOW_AUTOSIZE);
			imshow("prew", original);
			
			//terminating if esc pressed
			int key1 = waitKey(20);
			if ((char)key1 == 27) { break; }

		}
	}
	return 0;
}


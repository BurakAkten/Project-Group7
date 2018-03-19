/*// CannyStill.cpp

#include<opencv2/opencv.hpp>

#include<iostream>
#include<conio.h>           // may have to modify this line if not using Windows

///////////////////////////////////////////////////////////////////////////////////////////////////
int main() {
cv::Mat imgOriginal;        // input image
cv::Mat imgGrayscale;       // grayscale of input image
cv::Mat imgBlurred;         // intermediate blured image
cv::Mat imgCanny;           // Canny edge image

imgOriginal = cv::imread("image.png");          // open image

if (imgOriginal.empty()) {                                  // if unable to open image
std::cout << "error: image not read from file\n\n";     // show error message on command line
_getch();                                               // may have to modify this line if not using Windows
return(0);                                              // and exit program
}

cv::cvtColor(imgOriginal, imgGrayscale, CV_BGR2GRAY);       // convert to grayscale

cv::GaussianBlur(imgGrayscale,          // input image
imgBlurred,                         // output image
cv::Size(5, 5),                     // smoothing window width and height in pixels
1.5);                               // sigma value, determines how much the image will be blurred

cv::Canny(imgBlurred,           // input image
imgCanny,                   // output image
82,                         // low threshold
164);                       // high threshold

// declare windows
cv::namedWindow("imgOriginal", CV_WINDOW_AUTOSIZE);     // note: you can use CV_WINDOW_NORMAL which allows resizing the window
cv::namedWindow("imgCanny", CV_WINDOW_AUTOSIZE);        // or CV_WINDOW_AUTOSIZE for a fixed size window matching the resolution of the image
// CV_WINDOW_AUTOSIZE is the default
cv::imshow("imgOriginal", imgOriginal);     // show windows
cv::imshow("imgCanny", imgCanny);

cv::waitKey(0);                 // hold windows open until user presses a key

return(0);
}*/


#include "opencv2/highgui/highgui.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/objdetect/objdetect.hpp"
#include <iostream>
#include <opencv2/videoio.hpp>



using namespace cv;
using namespace std;

void cropImage();
int detectFromImg(String ImageName , CascadeClassifier detector);
int detectFromCam(CascadeClassifier detector);




int main() {
	try {

		

		cropImage();

		CascadeClassifier face;
		string cascadeName = "haarcascade_frontalface_alt.xml";
		string cascadeName2 = "haarcascade_fullbody.xml";
		bool loaded = face.load(cascadeName);
		if (loaded == false)
			return -2;

		detectFromImg("image2.jpg",face);

		detectFromCam(face);




		
	}
	catch (Exception x) {
		namedWindow(x.msg, CV_WINDOW_FREERATIO);
		Mat image = imread("image.png");
		imshow(x.msg, image);
		waitKey(0);
	}
	return 0;
}


void cropImage() {

	namedWindow("image2", CV_WINDOW_FREERATIO);
	namedWindow("image", CV_WINDOW_FREERATIO);

	Mat image = imread("image.png");
	Mat image2 = image(Rect(94, 256, 784, 344));

	imshow("image", image);
	imshow("image2", image2);
	
	waitKey(0);

}

int detectFromImg(String ImageName , CascadeClassifier detector)
{
	Mat capF, grayF;

	capF = imread(ImageName);
	imshow("original", capF);
	cvtColor(capF, grayF, CV_BGR2GRAY);
	vector<Rect> faces;

	detector.detectMultiScale(grayF, faces, 1.1, 3, CV_HAAR_FIND_BIGGEST_OBJECT | CV_HAAR_SCALE_IMAGE, Size(30, 30));

	for (int i = 0; i < faces.size(); i++)
	{
		Point pt1(faces[i].x + faces[i].width, faces[i].y + faces[i].height);
		Point pt2(faces[i].x, faces[i].y);

		rectangle(capF, pt1, pt2, cvScalar(0, 255, 0, 0));
	}

	imshow("lats", capF);


	waitKey(0);
	
	return 0;

}


int detectFromCam(CascadeClassifier detector) {

	VideoCapture cap;
	cap.open(0);
	if (!cap.isOpened())
	return -1;


	Mat capF, grayF;


	for (;;)
	{
		cap >> capF;
		cvtColor(capF, grayF, CV_BGR2GRAY);

		equalizeHist(grayF, grayF);

		vector<Rect> faces;

		detector.detectMultiScale(grayF, faces, 1.1, 3, CV_HAAR_FIND_BIGGEST_OBJECT | CV_HAAR_SCALE_IMAGE, Size(30, 30));

		for (int i = 0; i < faces.size(); i++)
		{
			Point pt1(faces[i].x + faces[i].width, faces[i].y + faces[i].height);
			Point pt2(faces[i].x, faces[i].y);

			rectangle(capF, pt1, pt2, cvScalar(0, 255, 0, 0));
		}


		imshow("lats", capF);


		waitKey(33);
	}

}



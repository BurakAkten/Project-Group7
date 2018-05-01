#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

#include<iostream>
#include<fstream>
#include "math.h"

#include <opencv2/opencv.hpp>


using namespace std;
using namespace cv;

vector<Scalar> colors;
void trackFilteredObject(vector<Mat> src, Mat original);

int main() {

	colors.push_back(Scalar(0, 0, 255));//red
	colors.push_back(Scalar(0, 128, 0));//green
	colors.push_back(Scalar(0, 255, 255));//yellow


	VideoCapture cap(0);//capture from webcam
	Mat frame;
	for (;;) {
		cap >> frame; //take frame
		Mat dst_image;
		resize(frame, dst_image, Size(frame.cols, frame.rows));
		imshow("Original input image: ", dst_image);

		// Create an output image
		vector<Mat> output(3);
		vector<Mat> dst_output(3);

		// Color range..
		inRange(frame, Scalar(13, 15, 139), Scalar(85, 56, 210), output[0]);//for red
		inRange(frame, Scalar(255, 255, 0), Scalar(255, 255, 150), output[1]);//for green
		inRange(frame, Scalar(47, 231, 253), Scalar(26, 211, 231), output[2]);//for yellow



																			  // Resize and show the image
		resize(output[0], dst_output[0], Size(output[0].cols, output[0].rows));
		imshow("Output red: ", dst_output[0]);

		resize(output[1], dst_output[1], Size(output[1].cols, output[1].rows));
		imshow("Output yellow: ", dst_output[1]);

		resize(output[2], dst_output[2], Size(output[2].cols, output[2].rows));
		imshow("Output red: ", dst_output[2]);

		trackFilteredObject(dst_output, dst_image);

		imshow("Last result", dst_image);

		if (waitKey(30) == 27) break;//wait for esc


	}
}


void trackFilteredObject(vector<Mat> src, Mat original) {


	for (size_t i = 0; i < src.size(); i++)
	{
		vector< vector<Point> > contours;
		vector<Vec4i> hierarchy;
		blur(src[i], src[i], Size(5, 5));

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
			double distance = 0;

			distance = 8414.7*pow(boundRect.area(), -0.468);//?
			cout << distance << " cm." << endl;

			stringstream ss;
			ss << "Distance : ";
			ss << distance;
			ss << " cm.";
			String dis = ss.str();
			putText(original, dis, Point(50, 50), CV_FONT_HERSHEY_COMPLEX, 1, Scalar(0, 0, 0));
		}
		else {
			// TODO
		}
	}
}










///////////////////////////////////////////////////////////////////////////////////////////////////
/*int main() {

	Mat img, img_gray, channel[3];
	VideoCapture cam(1);
	double distance = 0;


	cam.set(CV_CAP_PROP_FRAME_WIDTH, 1280);
	cam.set(CV_CAP_PROP_FRAME_HEIGHT, 720);
	cam.set(CV_CAP_PROP_CONVERT_RGB, 1);
	namedWindow("Frame", WINDOW_AUTOSIZE);




	while (waitKey(10) != 'a')
	{
		cam >> img;
		cvtColor(img, img_gray, COLOR_RGB2GRAY);
		split(img, channel);
		subtract(channel[2], img_gray, img_gray);
		//convertScaleAbs(img, img);
		threshold(img_gray, img_gray, 90, 255, THRESH_BINARY);

		erode(img_gray, img_gray, Mat(), Point(-1, -1), 4);
		dilate(img_gray, img_gray, Mat(), Point(-1, -1), 4);

		vector<vector<Size>> contors;
		vector<Vec4i> heirarcy;
		findContours(img_gray, contors, heirarcy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));

		vector<Rect> boundRect(contors.size());
		vector<vector<Point>> contor_poly(contors.size());

		for (int i = 0; i< contors.size(); i++)
		{
			approxPolyDP(Mat(contors[i]), contor_poly[i], 3, true);
			boundRect[i] = boundingRect(Mat(contor_poly[i]));
		}
		int max_index = 0, max_area = 0;
		for (int i = 0; i< boundRect.size(); i++)
		{
			int a = boundRect[i].area();
			rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(255, 255, 0), 2, 8, 0);
			if (a > max_area)
			{
				max_area = a;
				max_index = i;
			}
		}
		int confidence = 0;
		for (int i = 0; i< boundRect.size(); i++)
		{
			if ((boundRect[i].x < boundRect[max_index].x + boundRect[max_index].width && boundRect[i].x > boundRect[max_index].x - int(0.1*boundRect[max_index].width)) && (boundRect[i].y > boundRect[max_index].y))
				confidence += 45;

		}
		if (boundRect.size() > 0)
		{
			if (confidence > 99)
				confidence = 0;
			//try{
			//Mat sub_image = Mat(img, Rect(max(boundRect[max_index].x-30, 0), max(boundRect[max_index].y-30, 0), min(int(boundRect[max_index].width*1.75), img.cols - boundRect[max_index].x+30), min(boundRect[max_index].height*3, img.rows - boundRect[max_index].y+30)));
			//imshow("Frame", sub_image);
			//}catch(int e){
			//	cout<<"Error occured"<<endl;
			//}
			rectangle(img, boundRect[max_index].tl(), boundRect[max_index].br(), Scalar(0, 255, 0), 2, 8, 0);

			//fprintf(data,"%d , %d , %d\n", boundRect[max_index].width, boundRect[max_index].height, boundRect[max_index].area());
			distance = 8414.7*pow(boundRect[max_index].area(), -0.468);
			cout << distance << " cm." << " Confidence: " << confidence << endl;
			imshow("Frame", img);

		}

		else
			imshow("Frame", img);
	}


	cam.release();
	
	return(0);
}*/
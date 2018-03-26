#include "opencv2/opencv.hpp"

#include <opencv2/core/utility.hpp>
#include <opencv2/video/tracking.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include "opencv2/imgcodecs.hpp"
#include <opencv2/highgui.hpp>
#include <opencv2/ml.hpp>

#include <iostream>
#include <fstream>
#include <vector>

#define DUMP        0
#define VEHICLE     1
#define CAR			0
#define MINIVAN		1


#define PATCH_SIZE  Size(128, 128)
#define IMAGE_SIZE  Size(640, 480)
#define STRIDE_SIZE	Size(2, 2)
using namespace std;
using namespace cv;
using namespace cv::ml;


vector< vector< Point> > getContours(Mat& img);
int checkCollision(vector< Rect > rects, int y);
void mergeOverlaps(vector<Rect> &inputBoxes, Size size, vector<Rect> &outputBoxes);
void trainSvm(Ptr<SVM>& svm, Mat& data, Mat& label);
void extractHogAndTrainSVM(Ptr<SVM> &svm, string file1, string file2);




float compareHogFeatures(vector<float>& h1, vector<float>& h2)
{
	float dist = 0.0;
	for (size_t i = 0; i < h1.size(); i++)
	{
		dist += abs(h1[i] - h2[i]);
	}
	return dist;
}


int findFeatureIndex(vector< vector< float > > features, vector< float > f)
{
	int res = 0;
	for (size_t i = 0; i < features.size(); i++)
	{
		res = (int)compareHogFeatures(features[i], f);
		if (500 > res)
			return (int)i;

	}
	return -1;
}


int main(int argc, char ** argv)
{
	Ptr<SVM> classifier;
	Ptr<SVM> detector;

	vector< vector< Point > > custom_roi;
	//int carcount = 0;
	int prevCount = 10000;
	Mat frame, out, fg, mask, custom_roi_mask;
	VideoCapture capture("traffic.mp4");
	/*VideoCapture capture;
	capture.open(0);
	if (!capture.isOpened())
		return -1;*/

	Ptr<BackgroundSubtractor> subtractorMog2;
	HOGDescriptor descriptor;


	custom_roi.push_back(vector<Point>());
	/*custom_roi[0].push_back(Point(255, 255));
	custom_roi[0].push_back(Point(300, 255));
	custom_roi[0].push_back(Point(250, 480));
	custom_roi[0].push_back(Point(120, 480));*/


	
	custom_roi[0].push_back(Point(10, 10));
	custom_roi[0].push_back(Point(630, 10));
	custom_roi[0].push_back(Point(630, 470));
	custom_roi[0].push_back(Point(10, 470));
	
	//set roi
	custom_roi_mask = Mat::zeros(IMAGE_SIZE, CV_8UC1);
	drawContours(custom_roi_mask, custom_roi, 0, Scalar(255), CV_FILLED, 8);
	mask = Mat::zeros(IMAGE_SIZE, CV_8UC1);


	descriptor.winSize = PATCH_SIZE;
	subtractorMog2 = createBackgroundSubtractorMOG2();

	//extract and train
	//extractHogAndTrainSVM(classifier, "cars.txt", "vans.txt");

	int choice;
	cout << "Train and save a new model(1) or Use a exist model(2)!!\n";
	cin >> choice;


	if (choice == 1) {
		extractHogAndTrainSVM(detector, "dumps.txt", "cars.txt");
		detector->save("my_det.xml");
		cout << "New model saved!";
	}
	else if (choice == 2) {
		detector = StatModel::load<SVM>("my_det.xml");
	}

	
	vector< vector< float> > prev_features;

	vector < Scalar > colors;
	colors.push_back(Scalar(0, 0, 255));
	colors.push_back(Scalar(0, 255, 0));
	colors.push_back(Scalar(255, 0, 0));

	for (int i = 0; i > -1; ++i) {
		capture >> frame;
		resize(frame, frame, IMAGE_SIZE);

		out = Mat::zeros(frame.size(), frame.type());
		frame.copyTo(out, custom_roi_mask);

		subtractorMog2->apply(out, mask);
		out.copyTo(fg, mask);

		cvtColor(fg, fg, CV_BGR2GRAY);
		//I added
		equalizeHist(fg, fg);
		blur(fg, fg, Size(5, 5));
		threshold(fg, fg, 30, 250, THRESH_BINARY);
		imshow("before dilation", fg);

		int dilateSize = 3;
		// types : MORPH_RECT, MORPH_CROSS, MORPH_ELLIPSE
		Mat element = getStructuringElement(MORPH_RECT,
			Size(2 * dilateSize + 1, 2 * dilateSize + 1),
			Point(dilateSize, dilateSize));
		dilate(fg, fg, element);
		imshow("after dilation", fg);

		vector< vector< Point > > contours = getContours(fg);
		vector< vector< Point > > hull(contours.size());
		for (int j = 0; j < contours.size(); j++) {
			convexHull(Mat(contours[j]), hull[j], false);
		}

		vector< Rect > rects, rects_out;
		for (int j = 0; j< contours.size(); j++) {
			Rect r = boundingRect(hull[j]);
			if (r.area() > 1000)
				rects.push_back(r);
		}

		mergeOverlaps(rects, frame.size(), rects_out);

		/*int index = checkCollision(rects_out, 260);
		if (index != -1) {
			carcount++;
		}*/


		vector< vector< float > > temp;
		for (size_t a = 0; a < rects_out.size(); a++)
		{
			vector< float > descriptorsValues;
			vector< Point > locations;
			Mat himg;
			if (!Rect(0, 0, 640, 480).contains(rects_out[a].tl()) || !Rect(0, 0, 640, 480).contains(rects_out[a].br())) continue;

			himg = frame(rects_out[a]).clone();
			resize(himg, himg, PATCH_SIZE);
			descriptor.compute(himg, descriptorsValues, STRIDE_SIZE, Size(0, 0), locations);

			//check if is it vehicle
			
			if (detector->predict(descriptorsValues) == DUMP) continue;

			int index = findFeatureIndex(prev_features, descriptorsValues);
			if (index != -1) rectangle(frame, rects_out[a], colors[index], 2);
			if (rects_out.size() == 1) rectangle(frame, rects_out[a], colors[0], 2);

			//check vehicle type
			//float res = classifier->predict(descriptorsValues);

			stringstream ss;
			//ss << (res == 0 ? "CAR" : "VAN");
			//putText(frame, ss.str(), rects_out[a].tl(), CV_FONT_HERSHEY_PLAIN, 1, Scalar(0, 255, 0));
			//ss.str("");

			temp.push_back(descriptorsValues);
		}

		prev_features = temp;
		stringstream ss;
		//ss << "Counter : " << carcount;
		putText(frame, ss.str(), Point(0, 25), CV_FONT_HERSHEY_PLAIN, 1, Scalar(0, 0, 0), 2);
		ss.str("");
		/*line(frame, custom_roi[0][0], custom_roi[0][2], Scalar(0, 255, 255), 2);
		line(frame, custom_roi[0][0], custom_roi[0][1], Scalar(0, 255, 255), 2);
		line(frame, custom_roi[0][1], custom_roi[0][3], Scalar(0, 255, 255), 2);
		line(frame, custom_roi[0][2], custom_roi[0][3], Scalar(0, 255, 255), 2);*/

		line(frame, custom_roi[0][0], custom_roi[0][1], Scalar(0, 255, 255), 2);
		line(frame, custom_roi[0][0], custom_roi[0][3], Scalar(0, 255, 255), 2);
		line(frame, custom_roi[0][1], custom_roi[0][2], Scalar(0, 255, 255), 2);
		line(frame, custom_roi[0][2], custom_roi[0][3], Scalar(0, 255, 255), 2);



		imshow("Result", frame);
		if (waitKey(30) == 27) break;
	}
	return 0;
}

void extractHogAndTrainSVM(Ptr<SVM> &svm, string file1, string file2)
{
	vector < vector<float> > all_descriptors;
	vector < vector< Point> > all_locations;
	vector < int > labels;

	fstream ifs(file1.c_str()), ifs2(file2.c_str());
	if (!ifs.is_open() || !ifs2.is_open())
	{
		cout << "File can not opened " << endl;
		return;
	}
	HOGDescriptor descriptor;
	descriptor.winSize = PATCH_SIZE;

	Mat img;
	for (int i = 0; /*i < 250 &&*/ !ifs.eof(); ++i)
	{
		string line;
		ifs >> line;
		if (line[line.size() - 1] == '\n') line = line.substr(0, line.size() - 1);
		if (line[line.size() - 1] == '\r') line = line.substr(0, line.size() - 1);
		cout << line << endl;
		img = imread(line);
		if (!img.data) continue;
		resize(img, img, PATCH_SIZE);

		vector< float> descriptorsValues;
		vector< Point> locations;
		descriptor.compute(img, descriptorsValues, STRIDE_SIZE, Size(0, 0), locations);

		all_descriptors.push_back(descriptorsValues);
		all_locations.push_back(locations);
		labels.push_back(CAR);
	}
	while (!ifs2.eof())
	{
		string line;
		ifs2 >> line;
		if (line[line.size() - 1] == '\n') line = line.substr(0, line.size() - 1);
		if (line[line.size() - 1] == '\r') line = line.substr(0, line.size() - 1);
		cout << line << endl;
		img = imread(line);
		if (!img.data) continue;
		resize(img, img, PATCH_SIZE);

		vector< float> descriptorsValues;
		vector< Point> locations;
		descriptor.compute(img, descriptorsValues, STRIDE_SIZE, Size(0, 0), locations);

		all_descriptors.push_back(descriptorsValues);
		all_locations.push_back(locations);
		labels.push_back(MINIVAN);
	}
	cout << "READING COMPLETED" << endl;

	int row = (int)all_descriptors.size();
	int col = (int)all_descriptors[0].size();

	cout << "row= " << row << endl
		<< "col= " << col << endl;

	Mat data_mat(row, col, CV_32F);
	Mat label_mat(row, 1, CV_32SC1);

	for (int i = 0; i < row; ++i)
	{
		memcpy(&(data_mat.data[col * i * sizeof(float)]), all_descriptors[i].data(), col * sizeof(float));
		label_mat.at<int>(i) = labels[i];
	}

	trainSvm(svm, data_mat, label_mat);
}

void trainSvm(Ptr<SVM>& svm, Mat& train_data, Mat& labels)
{
	svm = SVM::create();
	svm->setType(SVM::C_SVC);
	svm->setKernel(SVM::LINEAR);
	svm->setTermCriteria(TermCriteria(TermCriteria::MAX_ITER, 10000, 1e-6));

	Ptr<TrainData> td = TrainData::create(train_data, ROW_SAMPLE, labels);
	cout << "Train----------------------------------------->"<<endl;
	svm->train(td);
}



void mergeOverlaps(vector<Rect> &inputBoxes, Size size, vector<Rect> &outputBoxes)
{
	Mat mask = Mat::zeros(size, CV_8UC1);
	Size scaleFact(5, 5);
	for (int i = 0; i < inputBoxes.size(); i++)
	{
		Rect box = inputBoxes.at(i);
		rectangle(mask, box, Scalar(255), CV_FILLED);
	}

	vector<vector<Point> > contours;
	findContours(mask, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE);
	for (int j = 0; j < contours.size(); j++)
		outputBoxes.push_back(boundingRect(contours.at(j)) + scaleFact);
}


vector< vector< Point> > getContours(Mat& img)
{
	vector< vector< Point> > contours;
	vector<Vec4i> hierarchy;

	findContours(img, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));
	return contours;
}

int checkCollision(vector< Rect > rects, int y)
{
	for (int i = 0; i < rects.size(); ++i) {
		if (rects[i].tl().y == y)
			return i;
	}

	return -1;
}


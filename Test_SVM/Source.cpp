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

#define BACKROUND 0
#define WANTED 1


#define PATCH_SIZE  Size(128, 128)
#define IMAGE_SIZE  Size(640, 480)
#define STRIDE_SIZE	Size(2, 2)

typedef int Row;
typedef int Col;

using namespace std;
using namespace cv;
using namespace cv::ml;


void trainSvm(Ptr<SVM>& svm, Mat& data, Mat& label);
void extractHogAndTrainSVM(Ptr<SVM> &svm, string file1, string file2);


Mat cropImage(Row x, Col y, int w, int h , Mat frame);

int main(int argc, char** argv) {

	int choice;
	cout << "Train and save a new model(1) or Use a exist model(2)!!\n";
	cin >> choice;

	Ptr<SVM> detector;
	if (choice == 1) {
		extractHogAndTrainSVM(detector, "negatif.txt", "pozitif.txt");
		detector->save("my_det.xml");
		cout << "New model saved!";
	}
	else if (choice == 2) {
		detector = StatModel::load<SVM>("my_det.xml");
	}
	

	Mat frame , grayFrame;
	String ImageName;
	ImageName = "34.jpg";


	try {
		frame = imread(ImageName);
		cvtColor(frame, grayFrame, CV_BGR2GRAY);
		
		
		for (Row row = 0; row < 640; row += 50) {
			for (Col col = 0; col < 480; col += 50)
			{
				cout << "Row : " << row << " Col : " << col << endl;

				Mat littleFrame = cropImage(row, col, 100, 180, grayFrame);
				HOGDescriptor descriptor;
				descriptor.winSize = PATCH_SIZE;

				vector< float> descriptorsValues;
				vector< Point> locations;

				resize(littleFrame, littleFrame, PATCH_SIZE);
				descriptor.compute(littleFrame, descriptorsValues, STRIDE_SIZE, Size(0, 0), locations);
				
				float result = detector->predict(descriptorsValues);
				if (result == WANTED) {
					cout << "Result : " << result << endl;
					cout << "Row : " << row << " Col : " << col << endl;
					rectangle(frame, Rect(row, col, 80, 160), Scalar(0, 255, 255), 2);
				}
			}
		}
	}
	catch (Exception e) {
		cout << e.what() << endl;
		system("pause");

	}
	imshow("gray", grayFrame);
	imshow("Result", frame);
	imwrite("result.png", frame);
	
	waitKey(0);


	//system("pause");


	
	return 0;
}

Mat cropImage(Row x, Col y, int w, int h , Mat frame ) {
	
	int x1 = x;
	int y1 = y;

	//Mat image = imread(name);
	Mat image2 = frame(Rect(x1, y1, w, h));


	return image2;
}

void extractHogAndTrainSVM(Ptr<SVM> &svm, string file1, string file2)
{
	vector < vector<float> > all_descriptors;
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
	for (int i = 0;  !ifs.eof(); ++i)
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
		
		labels.push_back(BACKROUND);
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
		
		labels.push_back(WANTED);
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
	cout << "Train----------------------------------------->" << endl;
	svm->train(td);
}

























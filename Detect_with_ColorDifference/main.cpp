#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "fileContent.h"


#define MAXPOSSIBLE 50
using namespace std;
using namespace cv;

void trackFilteredObject(Mat src, Mat original);
void print(Mat toPrint);

Mat dst_output;
//max number of objects to be detected in frame
const int MAX_NUM_OBJECTS=50;
//minimum and maximum object area
const int MIN_OBJECT_AREA = 20*20;

int main(){

    // Create fileContent object
    fileContent images;
    images.readDirectory("DATASET");

    while( !images.fileNames.empty() ){

        // Get image name and add the file path
        string imageName = images.fileNames.front();
        imageName = "DATASET/" + imageName;

        // Open the image
        Mat image = imread(imageName);

        // Resize and show
        Mat dst_image;
        resize(image, dst_image, Size(image.cols/5, image.rows/5));
        imshow("Original input image: ", dst_image);

        // Create an output image
        Mat output;

        // Color range..
        inRange(image, Scalar(13, 15, 139), Scalar(85,56,210), output);

        // Resize and show the image

        resize(output, dst_output, Size(output.cols/5, output.rows/5));
        imshow("Output image: ", dst_output);

        trackFilteredObject(dst_output, dst_image);

        imshow("Last result", dst_image);
        waitKey();

        images.fileNames.pop();

    }

}

void trackFilteredObject(Mat src, Mat original){

    //these two vectors needed for output of findContours
    vector< vector<Point> > contours;
    vector<Vec4i> hierarchy;

    blur(src, src, Size(5,5));
    //find contours of filtered image using openCV findContours function
    findContours(src,contours,hierarchy,CV_RETR_CCOMP,CV_CHAIN_APPROX_SIMPLE );

    int numOfDetected = contours.size();
    int maxArea = 0;
    int required;

    if(numOfDetected < 50 && numOfDetected != 0){

        // Find the contours that has largest area
        for (int index = 0; index >= 0; index = hierarchy[index][0]) {
            Moments moment = moments((cv::Mat)contours[index]);
            double area = moment.m00;

            if (area > maxArea){
                maxArea = area;
                required = index;
            }

        }

        // Draw contours
        drawContours(original, contours, required, (0,255,0), 3);

    } else{
        cout << "So much noise" << endl;
    }


}


void print(Mat toPrint){

    for(int i = 0; i < toPrint.rows; ++i){
        for(int j = 0; j < toPrint.cols; ++j){
            cout << toPrint.at<double>(i,j) << " ";
        }
    }
}
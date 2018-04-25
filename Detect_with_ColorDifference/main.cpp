#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "fileContent.h"


#define MAX_LENGTH 50
using namespace std;
using namespace cv;

void trackFilteredObject(Mat src, Mat original);
void saveAsError(Mat toSave);
int countGlob = 1;

int main(){

    Mat dst_output;
    // Create fileContent object
    fileContent contentF;
    contentF.readDirectory("DATASET");

    queue<string> images = contentF.getFileNames();

    while( !images.empty() ){

        // Get image name and add the file path
        string imageName = images.front();
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

        images.pop();

    }

}

void trackFilteredObject(Mat src, Mat original){

    //these two vectors needed for output of findContours
    vector< vector<Point> > contours;
    vector<Vec4i> hierarchy;

    blur(src, src, Size(5,5));
    //find contours of filtered image using openCV findContours function
    findContours(src,contours,hierarchy,CV_RETR_CCOMP,CV_CHAIN_APPROX_SIMPLE );

    int numOfDetected = static_cast<int>(contours.size());
    int maxArea = 0;
    int required;


    if(numOfDetected < 500 && numOfDetected != 0){

        // Find the contours that has largest area
        for (int index = 0; index >= 0; index = hierarchy[index][0]) {
            Moments moment = moments((cv::Mat)contours[index]);
            double area = moment.m00;

            if (area > maxArea){
                maxArea = area;
                required = index;
            }

        }

        // Get bounding rectangle
        vector<Point> contours_points;
        // Approximates a polygonal curve with the specified precision
        approxPolyDP( Mat(contours[required]), contours_points, 3, true );
        // Calculate the up-right bounding rectangle of a point set
        Rect boundRect = boundingRect( Mat(contours_points) );


        // Draw contours
        // drawContours(original, contours, required, (0,0,0), 1);

        // Draw the specified rectangle
        rectangle( original, boundRect.tl(), boundRect.br(), (0,255,0), 2, 8, 0 );

    } else{
        saveAsError(original);
    }


}

void saveAsError(Mat toSave) {
    // Create image name
    char name[MAX_LENGTH];
    sprintf(name, "LOG/negative-%d.jpg", countGlob);
    cout << name << endl;
    // save the image
    imwrite(name, toSave);
    countGlob ++;
}


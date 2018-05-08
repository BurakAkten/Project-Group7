#include <iostream>
#include <dirent.h>
#include <queue>
#include "Recognation.h"

using namespace std;

queue<string> readDirectory(const string &dirName);

int main() {
    std::cout << "Here we begin!" << std::endl;

    // Open images
//    queue<string> files = readDirectory("DATASET");
//
//    while( !(files.empty())){
//        // Get image name and add the file path
//        string imageName = files.front();
//        imageName = "DATASET/" + imageName;
//
//        Recognation module;
//        module.run(imageName);
//        files.pop();
//    }

    // Open video
//    VideoCapture capture;
//    capture.open("cam.mp4");
//
//    Mat cameraFeed;
//
//    while(true){
//        // Take frame
//        capture >> cameraFeed;
//
//        Recognation module;
//        module.run(cameraFeed);
//
//    }

    // Open cam
    //Video capture object to acquire webcam feed

    Recognation module;
    Mat cameraFeed;

    VideoCapture capture;
    capture.open(0);

    while(true){
        capture >> cameraFeed;

        Mat result = module.run(cameraFeed);
        imshow("No helmet", result);
        imwrite("red.jpg", result);
        if( waitKey(20) == ESC){ break; }
    }


    return 0;
}


queue<string> readDirectory(const string &dirName) {

    // Open the directory
    DIR* dirp = opendir(dirName.c_str());

    // Create dirent struct
    struct dirent * dp;

    queue<string> fileNames;

    while ((dp = readdir(dirp)) != NULL) {
        fileNames.push(dp->d_name);
    }

    // The first 2 name is . and ..
    fileNames.pop();
    fileNames.pop();

    closedir(dirp);

    return fileNames;

}
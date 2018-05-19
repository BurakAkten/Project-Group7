#include <iostream>
#include <dirent.h>
#include <queue>
#include "Recognation.h"
#include <sstream> // for ostringstream

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
    vector<Mat> databaseFrames;

    int fCount = 0;
    Mat result;
    std::ostringstream out;

    while(true){
        capture >> cameraFeed;

        bool res = module.run(cameraFeed, result);

        if(res){
            cout << "Baret yok" << endl;
            imshow("Result", result);
        }
        else{
            imshow("Result", cameraFeed);
        }


        if(fCount == 300){
            databaseFrames = module.getDatabaseFrames();
            cout << "result size: " << databaseFrames.size() << endl;
            for(int i = 0; i < databaseFrames.size(); ++i){
                if(i == 0 || i == databaseFrames.size()-1 || i == databaseFrames.size()/2){
                    out << "OUTPUT/" << i << "_noHelmet.jpg";
                    imwrite(out.str(), databaseFrames.at(i));
                    imshow(out.str(), databaseFrames.at(i));
                    waitKey(0);
                    out.str("");
                }
            }
            module.clearDatabaseFrames();
            break;
        }
        fCount ++;
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
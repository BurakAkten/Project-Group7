#include <iostream>
#include <dirent.h>
#include <queue>
#include "Recognation.h"

using namespace std;

queue<string> readDirectory(const string &dirName);

int main() {
    std::cout << "Here we begin!" << std::endl;
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

    Recognation module;
    module.run();

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
//
// Created by Şevval on 3.04.2018.
//

#include "fileContent.h"
#include <dirent.h>


void fileContent::readDirectory(const string &dirName) {

    // Open the directory
    DIR* dirp = opendir(dirName.c_str());

    // Create dirent struct
    struct dirent * dp;

    while ((dp = readdir(dirp)) != NULL) {
        fileNames.push(dp->d_name);
    }

    // The first 2 name is . and ..
    fileNames.pop();
    fileNames.pop();

    closedir(dirp);

}

fileContent::fileContent() {
    // cout << "constructor" << endl;
}

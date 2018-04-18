//
// Created by Şevval on 3.04.2018.
//

#ifndef READFILECONTENT_H
#define READFILECONTENT_H
#include <iostream>
#include <queue>


using namespace std;

class fileContent {

public:
    fileContent();
    void readDirectory(const string& dirName);
    queue<string> fileNames;
};


#endif //READFILECONTENT_H

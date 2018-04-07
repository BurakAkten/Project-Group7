//
// Created by Vakhid Betrakhmadov on 31/03/2018.
//

#ifndef SERVER_MATCONVERTER_H
#define SERVER_MATCONVERTER_H

#include <iostream>
#include <vector>
#include <exception>
//#include "opencv2/imgproc.hpp"
//#include "opencv2/highgui.hpp"
#include "/home/furkan/Desktop/opencv-3.4.1/include/opencv2/opencv.hpp"

using namespace std;
using namespace cv;

namespace server_client {

    typedef unsigned char byte;

    class MatConverter {
        size_t matrixSize;
        size_t bufferSize;
        vector<byte> buffer;
    public:
        MatConverter();
        MatConverter(const Mat& mat);
        const vector<byte>& byteStream(const Mat &mat);
        static Mat makeMat(const vector<byte>& buffer);
    };
}

#endif //SERVER_MATCONVERTER_H

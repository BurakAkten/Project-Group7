//
// Created by Vakhid Betrakhmadov on 31/03/2018.
//

#ifndef MATCONVERTER_H
#define MATCONVERTER_H

#include <iostream>
#include <vector>
#include <exception>
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"

using namespace std;
using cv::Mat;

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

#endif //MATCONVERTER_H

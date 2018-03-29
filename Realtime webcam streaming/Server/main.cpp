// This is just a row TEST code version 0.0 with no optimizations, code structure and so on,
// that is, it's in no way meant to be used in production, but only for as reference or example.

#include <iostream>
#include <stdlib.h>
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "uici.h"
#include "restart.h"

#define DEFAULT_PORT 9898
#define WINDOW_NAME "window"

using namespace cv;
using namespace std;

typedef unsigned char byte;

byte* MatToBytes(const Mat& mat, int* bufferSizeOut) {
    int intSize = sizeof(int);
    int dataSize = mat.total() * mat.elemSize(); // <<<<< --------  this is the real size of the DATA !!!!!!!!!!!
    int bufferSize = intSize * 3 + dataSize;
    byte* buffer = new byte[bufferSize];
    memcpy(buffer, &mat.rows, intSize);
    memcpy(buffer + intSize, &mat.cols, intSize);
    int type = mat.type();
    memcpy(buffer + intSize * 2, &type, intSize);
    memcpy(buffer + intSize * 3, mat.data, dataSize);
    *bufferSizeOut = bufferSize;
    return buffer;
}

Mat bytesToMat(const byte* buffer) {
    int rows, cols, type;
    int intSize = sizeof(int);
    memcpy(&rows, buffer, intSize);
    memcpy(&cols, buffer + intSize, intSize);
    memcpy(&type, buffer + intSize * 2, intSize);
    int dataSize = sizeof(byte) * rows * cols;
    Mat mat = Mat(rows, cols, type, (void*)(buffer + intSize * 3)).clone();
    return mat;
}


int main(int argc, char** argv)
{
    int passive_sock_fd = 0;
    int private_sock_fd = 0;

    VideoCapture cap(0);
    if(!cap.isOpened()) return -1;

    if ((passive_sock_fd = u_open(DEFAULT_PORT)) == -1) {
        cout << "u_open" << endl;
        exit(1);
    }
    else if((private_sock_fd = u_accept(passive_sock_fd, NULL , 0)) == -1) {
        cout << "u_accept" << endl;
        exit(1);
    }

    Mat frame;
    int bytesWriten = 0;
    int bufferSize = 0;
    byte* buffer = NULL;
    for(;;)
    {
        cap >> frame;
        buffer = MatToBytes(frame, &bufferSize);

        int select_return_value;
        fd_set sockset;

        FD_ZERO(&sockset);
        FD_SET(private_sock_fd, &sockset);
        while ( ((select_return_value = select(private_sock_fd+1, NULL,  &sockset, NULL, NULL)) == -1) &&
               (errno == EINTR) ) {
          FD_ZERO(&sockset);
          FD_SET(private_sock_fd, &sockset);
        }

        cout << FD_ISSET(private_sock_fd, &sockset) << endl;

        if (select_return_value == -1) {
            cout << "select" << endl;
            exit(1);
        }

        cout << bufferSize << endl;

        if ((bytesWriten = r_write(private_sock_fd, (void*) &bufferSize, sizeof(int))) != sizeof(int)) {
            cout << "r_write" << endl
            << "bytesWriten: " << bytesWriten << endl
            << "errno: " << errno << endl;
            exit(1);
        }


        // if ((bytesWriten = send(private_sock_fd, buffer, bufferSize, 0)) != bufferSize) {
        //     cout << "r_write" << endl
        //     << "bytesWriten: " << bytesWriten << endl
        //     << "errno: " << errno << endl;
        //     exit(1);
        // }

        if ((bytesWriten = r_write(private_sock_fd, buffer, bufferSize)) != bufferSize) {
            cout << "r_write" << endl
            << "bytesWriten: " << bytesWriten << endl
            << "errno: " << errno << endl;
            exit(1);
        }

        delete buffer;

        if(waitKey(30) >= 0) break;
    }

    r_close(private_sock_fd);
    r_close(passive_sock_fd);

    return 0;
}
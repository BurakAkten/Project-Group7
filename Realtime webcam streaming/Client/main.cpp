// This is just a row TEST code version 0.0 with no optimizations, code structure and so on,
// that is, it's in no way meant to be used in production, but only for as reference or example.

#include <iostream>
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "restart.h"
#include "uici.h"

#define WINDOW_NAME "window"

using namespace std;
using namespace cv;

typedef unsigned char byte;

u_port_t port = 9898;
char* hostname = (char*) "localhost";

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


ssize_t rr_read(int fd, void *buf, size_t size) {
   char *bufp;
   size_t bytestoread;
   ssize_t bytesread;
   size_t totalbytes;

   for (bufp = (char*)buf, bytestoread = size, totalbytes = 0;
        bytestoread > 0;
        bufp += bytesread, bytestoread -= bytesread) {
      bytesread = read(fd, bufp, bytestoread);
      if ((bytesread) == -1 && (errno != EINTR))
         return -1;
      if (bytesread == -1)
         bytesread = 0;
      totalbytes += bytesread;
   }
   return totalbytes;
}

int main() {

    int private_socket_fd = 0;
    struct sockaddr_in server;

    server.sin_port = htons((short)port);
    server.sin_family = AF_INET;
    if (name2addr(hostname,&(server.sin_addr.s_addr)) == -1) {
        cout << "name2addr" << endl;
        exit(1);
    }

    if((private_socket_fd = u_connect(port,&server)) == -1) {
        cout << "u_connect" << endl;
        exit(1);
    }

    namedWindow(WINDOW_NAME);

    Mat frame;
    int bufferSize = 0;
    int bytesRead = 0;
    byte* buffer = NULL;

    for(;;) {

    	int select_return_value;
		fd_set sockset;

		FD_ZERO(&sockset);
		FD_SET(private_socket_fd, &sockset);
		while ( ((select_return_value = select(private_socket_fd+1, &sockset, NULL, NULL, NULL)) == -1) &&
		       (errno == EINTR) ) {
		  FD_ZERO(&sockset);
		  FD_SET(private_socket_fd, &sockset);
		}

		cout << FD_ISSET(private_socket_fd, &sockset) << endl;

		if (select_return_value == -1) {
			cout << "select" << endl;
			exit(1);
		}

        if((bytesRead = r_read(private_socket_fd, (void*) &bufferSize, sizeof(int))) != sizeof(int)) {
            cout << "r_write" << endl
            << "bytesRead: " << bytesRead << endl
            << "errno: " << errno << endl;
            exit(1);
        }

        cout << bufferSize << endl;

        buffer = new byte[bufferSize];

    //     if((bytesRead = recv(private_socket_fd, buffer, bufferSize, 0)) != bufferSize) {
			 // cout << "r_write" << endl
    //         << "bytesRead: " << bytesRead << endl
    //         << "errno: " << errno << endl;
    //         exit(1);
    //     }
        
        // if((bytesRead = r_read(private_socket_fd, buffer, bufferSize)) != bufferSize) {
        //     cout << "r_write" << endl
        //     << "bytesRead: " << bytesRead << endl
        //     << "errno: " << errno << endl;
        //     exit(1);
        // }    

        if((bytesRead = rr_read(private_socket_fd, buffer, bufferSize)) != bufferSize) {
            cout << "r_write" << endl
            << "bytesRead: " << bytesRead << endl
            << "errno: " << errno << endl;
            exit(1);
        } 

        frame = bytesToMat(buffer);	

        delete buffer;

        imshow(WINDOW_NAME, frame);

        if(waitKey(30) >= 0) break;
    }

    r_close(private_socket_fd);

    return  0;

}
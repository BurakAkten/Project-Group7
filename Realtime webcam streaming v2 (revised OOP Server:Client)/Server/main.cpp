#include <iostream>
#include <cstdlib>
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "supporting/uici.h"
#include "supporting/restart.h"
#include "MatConverter.h"
#include "Server.h"

using namespace cv;
using namespace std;
using namespace server_client;


void callback(Server& server) {

    VideoCapture cap(0);
    if(!cap.isOpened()) {
        err("cap.isOpened()");
        server.stop();
    }

    Mat frame;
    cap >> frame;
    MatConverter matConverter(frame);

    volatile bool connectionActive = true;
    for(;connectionActive;) {

        const vector<byte> &buffer = matConverter.byteStream(frame);
        long size = buffer.size();

        if (server.send(&size, sizeof(long)) != sizeof(long)) {
            err("server.send()");
            connectionActive = false;
        } else if (server.send(buffer) != buffer.size()) {
            err("server.send()");
            connectionActive = false;
        }

        if (!connectionActive && errno != EPIPE )
            server.stop();
        else
            cap >> frame;
    }
}

int main(int argc, char** argv) {
    Server server(callback);
    if (server.run()) {
        err("server.run()");
        exit(1);
    }

    return 0;
}
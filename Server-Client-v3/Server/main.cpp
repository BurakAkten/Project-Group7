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

    cout << "- CONNECTED -" << endl;

    VideoCapture cap(0);
    if(!cap.isOpened()) {
        err("cap.isOpened()");
        server.stop();
        return;
    }

    cap.set(cv::CAP_PROP_FRAME_WIDTH, 640);
    cap.set(cv::CAP_PROP_FRAME_HEIGHT, 480);

    Mat frame;
    Mat compressedFrame;

    volatile bool connectionActive = true;
    for(;connectionActive;) {

        cap >> frame;

        if(frame.empty()) {
            err("frame.empty()");
            connectionActive = false;
            continue;
        }

        pyrDown(frame, compressedFrame);

        if(server.send(compressedFrame)) {
            err("server.send()");
            connectionActive = false;
        }

        if (!connectionActive && errno != EPIPE ) { // EPIPE if connection is closed by the client
            err("Unknown error:");
//            server.stop();
        }
    }

    cap.release();

    cout << "- DISCONNECTED -" << endl;
}

int main(int argc, char** argv) {

    cout << "- SERVER STARTED -" << endl;

    Server server(callback);
    if (server.run()) {
        err("server.run()");
        exit(1);
    }

    cout << "- SERVER EXITED -" << endl;

    return 0;
}
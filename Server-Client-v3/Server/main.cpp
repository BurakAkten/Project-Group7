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
        return;
    }

    cap.set(cv::CAP_PROP_FRAME_WIDTH, 640);
    cap.set(cv::CAP_PROP_FRAME_HEIGHT, 480);

    Mat frame;
    MatConverter matConverter;

    volatile bool connectionActive = true;
    for(;connectionActive;) {

        cap >> frame;

        pyrDown(frame, frame);

        if(frame.empty()) {
            cout << "Frame is empty" << endl;
            connectionActive = false;
            continue;
        }

        const vector<byte>& buffer = matConverter.byteStream(frame);
        uint32_t bufferSize = (int) buffer.size();

        cout << "bufferSize: " << bufferSize << endl;

        if (server.send(&bufferSize, sizeof(uint32_t)) != sizeof(uint32_t)) {
            err("server.send()");
            connectionActive = false;
        } else if (server.send(buffer) != bufferSize) {
            err("server.send()");
            connectionActive = false;
        }

        if (!connectionActive && errno != EPIPE ) { // EPIPE if connection is closed by the client
            cout << "Some error happened" << endl;
//            server.stop();
        }
    }

    cap.release();

    cout << "Exiting" << endl;
}

int main(int argc, char** argv) {

    Server server(callback);
    if (server.run()) {
        err("server.run()");
        exit(1);
    }

    return 0;
}
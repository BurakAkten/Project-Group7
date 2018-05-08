#include <iostream>
//#include "opencv2/imgproc.hpp"
//#include "opencv2/highgui.hpp"
#include "Client/supporting/uici.h"
#include "Client/supporting/restart.h"
#include "Client/MatConverter.h"
#include "Client/Client.h"

#define WINDOW_NAME "WINDOW"

using namespace std;
using namespace cv;
using namespace server_client;
/*
void callback(Client& client) {

    namedWindow(WINDOW_NAME);

    Mat frame;
    unsigned long bufferSize = 0;
    vector<byte> buffer;

    bool connectionActive = true;
    for (;connectionActive;) {

        if (client.receive(&bufferSize, sizeof(long)) != sizeof(long)) {
            err("client.receive");
            connectionActive = false;
        } else {
            buffer.reserve(bufferSize);
            if (client.receive(buffer) != bufferSize) {
                err("client.receive");
                connectionActive = false;
            }
        }

        frame = MatConverter::makeMat(buffer);

        imshow(WINDOW_NAME, frame);

        if (waitKey(30) >= 0) break;
    }
}


int main() {

    Client client("localhost", callback);
    if (client.connect()) {
        err("client.connect()");
        exit(1);
    }

    return 0;
}
*/

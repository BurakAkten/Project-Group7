#include <iostream>
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "supporting/uici.h"
#include "supporting/restart.h"
#include "MatConverter.h"
#include "Client.h"

#define WINDOW_NAME "WINDOW"

using namespace std;
using namespace cv;
using namespace server_client;

void callback(Client& client) {

    namedWindow(WINDOW_NAME);

    Mat frame;
    long bufferSize = 0;
    vector<byte> buffer;

    bool connectionActive = true;
    for (;connectionActive;) {
        if (client.receive(&bufferSize, sizeof(int)) != sizeof(int)) {
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

        if (waitKey(30) >= 0) {
            client.disconnect();
            connectionActive = false;
        }
    }
}


int main() {

    Client client("10.1.131.135", callback);
    if (client.connect()) {
        err("client.connect()");
        exit(1);
    }

    return 0;
}
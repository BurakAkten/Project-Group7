#include <iostream>
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "MatConverter.h"
#include "Client.h"

#define WINDOW_NAME "WINDOW"

using namespace std;
using namespace server_client;
using cv::namedWindow;
using cv::Mat;
using cv::imshow;
using cv::waitKey;

void callback(Client& client) {

    namedWindow(WINDOW_NAME);

    Mat frame;
    int bufferSize = 0;
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
            client.disconnectFromServer();
            connectionActive = false;
        }
    }
}

int main() {

    Client client("10.1.130.40", callback);
    if (client.connectToServer()) {
        cout << WSAGetLastError() << endl;
        err("client.connect()");
        exit(1);
    }

    cout << "EXITING" << endl;

    return 0;
}
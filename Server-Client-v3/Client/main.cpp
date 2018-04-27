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
    uint32_t bufferSize = 0;
    vector<byte> buffer;

    bool connectionActive = true;
    for (;connectionActive;) {

        if (client.hasDataPending()) {
            cout << "Data pending " << client.dataPending() << endl;
        }
        else {
            cout << "No data pending" << endl;
        }

        if (client.receive(&bufferSize, sizeof(uint32_t)) != sizeof(uint32_t)) {
            err("client.receive");
            connectionActive = false;
        } else {
            cout << "bufferSize: " << bufferSize << endl;

            buffer.reserve(bufferSize);
            if (client.receive(buffer) != bufferSize) {
                err("client.receive");
                connectionActive = false;
            }
            else {
                frame = MatConverter::makeMat(buffer);

                pyrUp(frame, frame);

                imshow(WINDOW_NAME, frame);

                if (waitKey(30) >= 0) {
                    client.disconnect();
                    connectionActive = false;
                }
            }
        }
    }

    destroyAllWindows();
}


int main() {

    Client client("10.1.44.28", callback); //10.1.44.28
    if (client.connect()) {
        err("client.connect()");
        exit(1);
    }

    return 0;
}
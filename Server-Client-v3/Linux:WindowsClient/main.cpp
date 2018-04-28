#include <iostream>
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "MatConverter.h"
#include "Client.h"

#if defined(__linux__) || defined(__APPLE__)
    #include "supporting/uici.h"
    #include "supporting/restart.h"
#endif

#define WINDOW_NAME "WINDOW"

using cv::namedWindow;
using cv::Mat;
using cv::imshow;
using cv::waitKey;
using cv::destroyAllWindows;
using namespace std;
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
                    client.disconnectFromServer();
                    connectionActive = false;
                }
            }
        }
    }

    destroyAllWindows();
}

int main() {

    cout << "- SERVER HAS STARTED -" << endl;

    const string ipAddress = "10.1.44.28";

    #if defined(__linux__) || defined(__APPLE__)
        Client client(ipAddress, callback);
        if (client.connectToServer()) {
            err("client.connect()");
            exit(1);
        }
    #elif _WIN32
        Client client(ipAddress, callback);
        if (client.connectToServer()) {
            cout << WSAGetLastError() << endl;
            err("client.connect()");
            exit(1);
        }
    #endif

    cout << "- SERVER HAS EXITED -" << endl;

    return 0;
}
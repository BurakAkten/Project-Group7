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
    Mat decompressedFrame;

    bool connectionActive = true;
    for (;connectionActive;) {

        if (client.hasDataPending()) {
            cout << "Data pending " << client.dataPending() << endl;
        }
        else {
            cout << "No data pending" << endl;
        }

        if(client.receive(frame)) {
            err("client.receive()");
            connectionActive = false;
        } else {

            pyrUp(frame, decompressedFrame);

            imshow(WINDOW_NAME, decompressedFrame);

            if (waitKey(30) >= 0) {
                client.disconnectFromServer();
                connectionActive = false;
            }
        }
    }

    destroyAllWindows();
}

int main() {

    cout << "- CLIENT STARTED -" << endl;

    const string ipAddress = "10.1.44.28";

    Client client(ipAddress, callback);
    if (client.connectToServer()) {
        err("client.connect()");
        #if _WIN32
            cout << WSAGetLastError() << endl;
        #endif
        exit(1);
    }

    cout << "- CLIENT EXITED -" << endl;

    return 0;
}
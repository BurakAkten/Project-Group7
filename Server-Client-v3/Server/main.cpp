#include <iostream>
#include <cstdlib>
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "supporting/uici.h"
#include "supporting/restart.h"
#include "MatConverter.h"
#include "Server.h"
#include "Command.h"
#include "Data.h"
#include "motor/Motor.h"
#include "image/Recognation.h"

using namespace motion;
using namespace cv;
using namespace std;
using namespace server_client;

#define WAIT_OUT_AREA 10
#define WAIT_IN_AREA 100

//TODO: Collibrate
#define RPM 245
#define DIAMETER 4.5
#define LEFT_POSITIVE true

#define XSTART 0
#define XEND 1000
const CriticalArea AREA1(200,400,0), AREA2(600,800,0);

inline int mid(int x1, int x2) {
    return x1 + ((x2 - x1) / 2);
}

inline void move(Motor &motor) {
    int location = (int) motor.getCurrentLocation();
    static bool movingLeft = false;

    if (location == XSTART) {
        motor.moveLeft(200);
        movingLeft = true;
    }
    else if (movingLeft && (location == AREA1.x1 || location == mid(AREA1.x1, AREA1.x2) || location == AREA2.x1 || location == mid(AREA2.x1, AREA2.x2))) {
        motor.moveLeft(100);
    }
    else if(movingLeft && (location == AREA1.x2 || location == AREA2.x2)) {
        motor.moveLeft(200);
    }
    else if (location == XEND) {
        motor.moveRight(200);
        movingLeft = false;
    }
    else if(!movingLeft && (location == AREA1.x2 || location == mid(AREA1.x1, AREA1.x2) || location == AREA2.x2 || location == mid(AREA2.x1, AREA2.x2))) {
        motor.moveRight(100);
    }
    else if(!movingLeft && (location == AREA1.x1 || location == AREA2.x1)) {
        motor.moveRight(200);
    }
}

void callback(Server& server) {

    cout << "- CONNECTED -" << endl;

    // Check if the camera is accesable
    VideoCapture cap(0);
    if(!cap.isOpened()) {
        err("cap.isOpened()");
        server.stop();
        return;
    }

    // Setup camera resolution
    cap.set(cv::CAP_PROP_FRAME_WIDTH, 640);
    cap.set(cv::CAP_PROP_FRAME_HEIGHT, 480);

    Mat frame;
    Mat processedFrame;
    Mat compressedFrame;
    Recognation recognizer;

    volatile bool connectionActive = true;
    Command command = Command::none;

    // Wait for start command
//    for(;connectionActive && command != Command::start;) {
//        if(server.receive(&command, sizeof(Command)) != sizeof(Command)) {
//            err("server.receive()");
//            connectionActive = false;
//        }
//        cout << command << endl;
//    }

    Motor& motor = Motor::getInstance(RPM, DIAMETER, LEFT_POSITIVE);
    int waitFramesInArea = WAIT_IN_AREA;
    int waitFramesOutArea = 0;
    int sentNoHelmetFramesCount = 0;
    bool started = false;
    bool stopped = false;
    int noHelmetAreaNumber = 0;

    Motor::State motorState;
    int location = 0;

    for(;connectionActive;) {

        cap >> frame;

        if(frame.empty()) {
            err("frame.empty()");
            connectionActive = false;
            continue;
        }

        motorState = motor.getCurrentState();
        location = (int) motor.getCurrentLocation();

        command = Command::none;
        if (started && motorState == Motor::State::stopped) {
            if(location == mid(AREA1.x1, AREA1.x2) || location == mid(AREA2.x1, AREA2.x2)) {
                if(waitFramesInArea != 0) {
                    --waitFramesInArea;
                    if(recognizer.run(frame, processedFrame)) {
                        pyrDown(processedFrame, compressedFrame);
                        if((sentNoHelmetFramesCount == 0 && waitFramesInArea <= 100) ||
                           (sentNoHelmetFramesCount == 1 && waitFramesInArea <= 60) ||
                           (sentNoHelmetFramesCount == 2 && waitFramesInArea <= 30)) {
                            noHelmetAreaNumber = (location == mid(AREA1.x1, AREA1.x2)) ? 1 : 2;
                            command = Command::no_helmet;
                            ++sentNoHelmetFramesCount;
                        }
                    } else {
                        pyrDown(frame, compressedFrame);
                    }
                } else {
                    waitFramesInArea = WAIT_IN_AREA;
                    move(motor);
                    pyrDown(frame, compressedFrame);
                    sentNoHelmetFramesCount = 0;
                }
            } else {
                if(waitFramesOutArea != 0 ) {
                    --waitFramesOutArea;
                } else {
                    move(motor);
                    waitFramesOutArea = WAIT_OUT_AREA;
                }
                pyrDown(frame, compressedFrame);
            }
        } else {
            pyrDown(frame, compressedFrame);
            if(stopped && motorState == Motor::State::stopped) {
                command = Command::init_point;
                stopped = false;
            }
        }

        if(server.send(&command, sizeof(Command)) != sizeof(Command)) {
            err("client.send()");
            connectionActive = false;
        } else if(command == Command::no_helmet && server.send(&noHelmetAreaNumber, sizeof(int)) != sizeof(int)) {
            err("client.send()");
            connectionActive = false;
        } else if(server.send(compressedFrame)) {
            err("server.send()");
            connectionActive = false;
        } else if(server.hasDataPending()) {
            if(server.receive(&command, sizeof(Command)) != sizeof(Command)) {
                err("server.receive()");
                connectionActive = false;
            } else if(command == Command::stop) {
                motor.stop();
                motor.moveRight(motor.getCurrentLocation());
                started = false;
                stopped = true;
//                connectionActive = false;
            } else if(command == Command::start) {
                started = true;
                stopped = false;
            }
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
#include <iostream>
#include "Motor.h"

#define QUIT "q"
#define STOP "s"
#define RIGHT "r"
#define LEFT "l"
#define STATE "t"

using namespace std;
using namespace motion;

void takeDistance(int& distance) {
    cin >> distance;
    cin.ignore(1000,'\n');
    cin.clear();
}

void takeCommand(string& command) {
    command = "";
    cin >> command;
    cin.ignore(1000,'\n');
    cin.clear();
}

void outputCurrentState(const Motor& motor) {
    cout << "RPM: " << motor.getRPM() << endl;
    cout << "diameter: " << motor.getDiameter() << endl;
    cout << "speed: " << motor.getSpeed() << endl;
    cout << "current location: " << motor.getCurrentLocation() << endl;

    cout << "state: ";
    if (motor.getCurrentState() == Motor::State::stopped) {
        cout << "stopped" << endl;
    } else if (motor.getCurrentState() == Motor::State::moving_left) {
        cout << "moving_left" << endl;
    } else if (motor.getCurrentState() == Motor::State::moving_right) {
        cout << "moving_right" << endl;
    }
}

int main() {

    Motor& motor = Motor::getInstance(500, 0.6, false);
    outputCurrentState(motor);

    string command;

    while(command.compare(QUIT) != 0) {

        takeCommand(command);

        if(command.compare(STOP) == 0) {
            cout << "STOP" << endl;
            motor.stop();
        } else if (command.compare(LEFT) == 0) {
            cout << "LEFT DISTANCE << ";
            int distance = 0;
            takeDistance(distance);
            motor.moveLeft(distance);
        } else if (command.compare(RIGHT) == 0) {
            cout << "RIGHT DISTANCE << ";
            int distance = 0;
            takeDistance(distance);
            motor.moveRight(distance);
        } else if (command.compare(STATE) == 0) {
            cout << "STATE" << endl;
            outputCurrentState(motor);
        }
    }

    return 0;
}
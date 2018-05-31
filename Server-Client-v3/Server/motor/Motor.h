//
// Created by Vakhid Betrakhmadov on 04/05/2018.
//

#ifndef MOTOR_H
#define MOTOR_H

//#include <wiringPi.h>
#include <sys/time.h>
#include <csignal>
#include <cstring>
#include <cmath>
#include <iostream>
#include <sstream>
#include "MotorException.h"

namespace motion {

    class Motor {

    // Nested types
    public:
        enum class State { stopped, moving_left, moving_right };

    // Public methods
        static Motor& getInstance(int rpm, double diameter, bool leftPositive);  // Fabric method
        int moveLeft(long distance);
        int moveRight(long distance);
        int stop();
        inline long getCurrentLocation() const { return currentLocation; }
        inline int getRPM() const { return rpm; }
        inline double getDiameter() const { return diameter; }
        inline double getSpeed() const { return speed; }
        inline State getCurrentState() const { return currentState; }

    // Private properties
    private:
        static Motor INSTANCE;                                                   // Singleton instance

        int rpm;                                                                 // Revolutions per minute
        double diameter;                                                         // Diameter of the wheel in sm
        double speed;                                                            // Linear speed in sm/sec
        long currentLocation;                                                    // Current location in sm relative 0 coordinate
        State currentState;
        int leftDirectionSign;                                                   // 1 if left direction is positive, -1 if negative
        struct itimerval timer;

    // Private methods
    private:
        Motor():Motor(0,0,0){};
        Motor(int theRPM, double theDiameter, int theLeftDirectionSign);
        Motor(Motor&);                                       // Don't Implement
        Motor& operator=(const Motor& other);

        void setTimerFor(long distance);
        void updateCurrentLocationOnEarlyStop(const struct itimerval* timer);
        void sigalrm_handler(int sig);
        inline int startTimer() const { return setitimer (ITIMER_REAL, &timer, nullptr); }
        inline int getTimerAndDisable(struct itimerval *timer) const {
            struct itimerval disable_timer; disable_timer.it_value.tv_sec = 0; disable_timer.it_value.tv_usec = 0;
            return setitimer (ITIMER_REAL, &disable_timer, timer);
        }
        inline void stopMotion() const {
//            digitalWrite(0,LOW); digitalWrite(2,LOW);
              std::cout << "stopMotion()" << std::endl;
        }
        inline void startRightMotion() const {
//            digitalWrite(0,HIGH); digitalWrite(2,LOW);
            std::cout << "startRightMotion()" << std::endl;
        }
        inline void startLeftMotion() const {
//            digitalWrite(0,LOW); digitalWrite(2,HIGH);
            std::cout << "startLeftMotion()" << std::endl;
        }

        static void static_sigalrm_handler(int sig) { INSTANCE.sigalrm_handler(sig); }
    };
}

#endif //MOTOR_H

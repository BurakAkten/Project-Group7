//
// Created by Vakhid Betrakhmadov on 04/05/2018.
//

#include "Motor.h"

namespace  {

    #define SEC_IN_MIN 60
    #define MILLION 1000000

    typedef void(*handler_t)(int);

    int ignoreSignal(int sig) {
        struct sigaction act;
        if (sigaction(sig, (struct sigaction *) nullptr, &act) == -1)
            return -1;
        act.sa_handler = SIG_IGN;
        return sigaction(sig, &act, (struct sigaction *)nullptr);
    }

    int setSignalHandler(int sig, handler_t handler) {
        struct sigaction act;
        act.sa_handler = handler;
        return sigaction(sig, &act, (struct sigaction *)nullptr);
    }
}

namespace motion {

    Motor Motor::INSTANCE;

    Motor& Motor::getInstance(int rpm, double diameter, bool leftPositive) {
        if (Motor::INSTANCE.speed  == 0 ) {
            Motor::INSTANCE = Motor(rpm, diameter, leftPositive ? 1 : -1);
            return Motor::INSTANCE;
        } else {
            return Motor::INSTANCE;
        }
    }

    Motor::Motor(int theRPM, double theDiameter, int theLeftDirectionSign)
            : rpm(theRPM),
              diameter(theDiameter),
              speed(rpm * diameter * M_PI / SEC_IN_MIN),
              currentLocation(0),
              currentState(State::stopped),
              leftDirectionSign(theLeftDirectionSign) {

        if (wiringPiSetup() == -1) {
            std::stringstream message("wiringPiSetup(); errno: ");
            message << errno;
            throw MotorException(message.str());
        }

        pinMode(0,OUTPUT);
        pinMode(1,OUTPUT);
        pinMode(2,OUTPUT);

        if(setSignalHandler(SIGALRM, Motor::static_sigalrm_handler)) {
            std::stringstream message("setSignalHandler(); errno: ");
            message << errno;
            throw MotorException(message.str());
        }

        timer.it_value.tv_sec = 0;
        timer.it_value.tv_usec = 0;
        timer.it_interval.tv_sec = 0;
        timer.it_interval.tv_usec = 0;
    }

    Motor& Motor::operator=(const Motor& other) {
        rpm = other.rpm;
        diameter = other.diameter;
        speed = other.speed;
        currentLocation = other.currentLocation;
        currentState = other.currentState;
        leftDirectionSign = other.leftDirectionSign;
        timer = other.timer;
        return *this;
    }

    int Motor::moveLeft(long distance) {
        if (stop())
            return -1;
        currentState = State::moving_left;
        currentLocation += (distance * leftDirectionSign);
        setTimerFor(distance);
        startLeftMotion();
        return startTimer();
    }

    int Motor::moveRight(long distance) {
        if (stop())
            return -1;
        currentState = State::moving_right;
        currentLocation += (distance * -leftDirectionSign);
        setTimerFor(distance);
        startRightMotion();
        return startTimer();
    }

    int Motor::stop() {
        if(ignoreSignal(SIGALRM))
            return -1;

        if (currentState != State::stopped) {
            stopMotion();
            if(getTimerAndDisable(&timer)) {
                int save_errno = errno;
                setSignalHandler(SIGALRM, Motor::static_sigalrm_handler);
                errno = save_errno;
                return -1;
            }
            updateCurrentLocationOnEarlyStop(&timer);
            currentState = State::stopped;
        }

        return setSignalHandler(SIGALRM, Motor::static_sigalrm_handler);
    }

    void Motor::sigalrm_handler(int sig) {
        if (currentState != State::stopped) {
            stopMotion();
            currentState = State::stopped;
        }
    }

    void Motor::setTimerFor(long distance) {
        double time = distance / speed;
        double fractpart = 0, intpart = 0;
        fractpart = modf(time, &intpart);
        timer.it_value.tv_sec = (int)intpart;
        timer.it_value.tv_usec = (int)(fractpart * MILLION); // convert sec to usec
    }

    void Motor::updateCurrentLocationOnEarlyStop(const struct itimerval* timer) {
        double timeLeft = timer->it_value.tv_sec + ((double)timer->it_value.tv_usec / MILLION );
        long distanceLeft = (long)(timeLeft * speed) * (currentState == State::moving_left ? -leftDirectionSign : leftDirectionSign);
        currentLocation += distanceLeft;
    }
}
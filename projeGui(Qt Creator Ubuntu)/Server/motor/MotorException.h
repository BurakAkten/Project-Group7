//
// Created by Vakhid Betrakhmadov on 05/05/2018.
//

#ifndef MOTOREXCEPTION_H
#define MOTOREXCEPTION_H

#include <iostream>

namespace motion {

    class MotorException: public std::exception {
        std::string message;
    public:
        inline MotorException(const std::string& theMessage) : message(theMessage) { }
        inline virtual const char* what() const throw() { return message.c_str(); }
    };
}

#endif //MOTOREXCEPTION_H

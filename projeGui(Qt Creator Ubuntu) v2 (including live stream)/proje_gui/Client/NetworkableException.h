//
// Created by Vakhid Betrakhmadov on 13/04/2018.
//

#ifndef SERVER_NETWORKABLEEXCEPTION_H
#define SERVER_NETWORKABLEEXCEPTION_H

#include <iostream>

using namespace std;

namespace server_client {

    class NetworkableException : public exception {
        string message;
    public:
        inline NetworkableException(const string &theMessage) : message(theMessage) {}
        inline virtual const char *what() const throw() { return message.c_str(); }
    };

}

#endif //SERVER_NETWORKABLEEXCEPTION_H

//
// Created by Vakhid Betrakhmadov on 03/04/2018.
//

#ifndef SERVER_NETWORKABLE_H
#define SERVER_NETWORKABLE_H

#include <iostream>
#include <cstdio>
#include <vector>
#include <sys/ioctl.h>
#include "supporting/uici.h"
#include "supporting/restart.h"

using namespace std;

namespace server_client {

    #ifndef err
    #define err(str) perror(str)
    #endif

    #ifndef DEFAULT_PORT
    #define DEFAULT_PORT 9898
    #endif

    typedef unsigned char byte;

    // TODO: hasDataPending test and modify
    // TODO: Checking whether the connection is active
    class Networkable {

    protected:
        int connection_sock_fd;

    public:
        Networkable();
        virtual ~Networkable();
        ssize_t send(const vector<byte>& buffer);
        ssize_t send(const void* buffer, size_t size);
        ssize_t receive(vector<byte> &buffer);
        ssize_t receive(void *buffer, size_t size);
        bool hasDataPending();

    private:
        ssize_t r_read_persistent(int fd, void *buf, size_t size);
    };


    class NetworkableException: public exception {
        string message;
    public:
        inline NetworkableException(const string& theMessage): message(theMessage) { }
        inline virtual const char* what() const throw() {  return message.c_str(); }
    };

}



#endif //SERVER_NETWORKABLE_H

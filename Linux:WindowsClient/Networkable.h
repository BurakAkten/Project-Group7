//
// Created by Vakhid Betrakhmadov on 03/04/2018.
//

#ifndef NETWORKABLE_H
#define NETWORKABLE_H

#include <iostream>
#include <cstdio>
#include <vector>
//#include "NetworkableException.h"

#ifdef __linux__
    #include <sys/ioctl.h>
    #include "supporting/uici.h"
    #include "supporting/restart.h"
    #include "NetworkableException.h"
#elif _WIN32
    #ifndef UNICODE
    #define UNICODE
    #endif

    #define WIN32_LEAN_AND_MEAN

    #include <winsock2.h>
    #include <Ws2tcpip.h>
    #include "wrestart.h"

    // Link with ws2_32.lib
    #pragma comment(lib, "Ws2_32.lib")
#endif

using namespace std;

namespace server_client {

#define DEFAULT_PORT 9898

#define err(str) perror(str)

    typedef unsigned char byte;

    class Networkable {

    protected:
        #ifdef __linux__
            int connection_sock_fd;
        #elif _WIN32
            SOCKET connection_sock_fd;
        #endif

    public:
        Networkable();
        virtual ~Networkable();
        ssize_t send(const vector<byte>& buffer) const;
        ssize_t send(const void* buffer, size_t size) const;
        ssize_t receive(vector<byte> &buffer) const;
        ssize_t receive(void *buffer, size_t size) const ;
        #ifdef __linux__
            bool hasDataPending() const;
            ssize_t dataPending() const;
        #endif
    };
}

#endif //NETWORKABLE_H
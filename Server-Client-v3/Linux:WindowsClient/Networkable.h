//
// Created by Vakhid Betrakhmadov on 03/04/2018.
//

#ifndef NETWORKABLE_H
#define NETWORKABLE_H

#include <iostream>
#include <cstdio>
#include <vector>
#include "NetworkableException.h"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"

#if defined(__linux__) || defined(__APPLE__)
    #include <sys/ioctl.h>
    #include "supporting/uici.h"
    #include "supporting/restart.h"
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
using cv::Mat;

namespace server_client {

#define DEFAULT_PORT 9898

#define err(str) perror(str)

    typedef unsigned char byte;

    class Networkable {

    protected:
        #if defined(__linux__) || defined(__APPLE__)
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

        int send(const Mat& mat) const;
        int receive(Mat& mat) const;

        bool hasDataPending() const;
        ssize_t dataPending() const;
    };
}

#endif //NETWORKABLE_H
//
// Created by Vakhid Betrakhmadov on 03/04/2018.
//

#ifndef NETWORKABLE_H
#define NETWORKABLE_H

#include <iostream>
#include <cstdio>
#include <vector>
#include <sys/ioctl.h>
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "supporting/uici.h"
#include "supporting/restart.h"
#include "NetworkableException.h"

using namespace std;
using cv::Mat;

namespace server_client {

    #define DEFAULT_PORT 9898

    #define err(str) perror(str)

    typedef unsigned char byte;

    class Networkable {

    protected:
        int connection_sock_fd;

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

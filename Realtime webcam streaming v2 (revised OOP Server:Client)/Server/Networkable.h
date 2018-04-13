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
#include "NetworkableException.h"

using namespace std;

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
        bool hasDataPending() const;
        ssize_t dataPending() const;
    private:
        ssize_t r_read_persistent(int fd, void *buf, size_t size) const;
    };
}

#endif //SERVER_NETWORKABLE_H

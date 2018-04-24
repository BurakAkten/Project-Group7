//
// Created by Vakhid Betrakhmadov on 03/04/2018.
//

#include "Networkable.h"

namespace  {
    #define BUFFER_SIZE 1024
}

namespace server_client {

    Networkable::Networkable():
                #ifdef __linux__
                    connection_sock_fd(0)
                #elif _WIN32
                    connection_sock_fd(INVALID_SOCKET)
                #endif
                {}

    Networkable::~Networkable() {
        #ifdef __linux__
            r_close(connection_sock_fd);
        #elif _WIN32
            if (connection_sock_fd != INVALID_SOCKET ) {
                shutdown(connection_sock_fd, SD_BOTH);
                closesocket(connection_sock_fd);
            }
        #endif
    }

    ssize_t Networkable::send(const vector<byte>& buffer) const {
        return send(buffer.data(), buffer.size());
    }

    ssize_t Networkable::send(const void* buffer, size_t size) const {
        #ifdef __linux__
            return r_write(connection_sock_fd, (void*) buffer, size);
        #elif _WIN32
            return  r_send(connection_sock_fd, (void*) buffer, size);
        #endif
    }

    ssize_t Networkable::receive(vector<byte> &buffer) const {
        #ifdef __linux__
            return readblock(connection_sock_fd, buffer.data(), buffer.capacity());
        #elif _WIN32
            return r_recv(connection_sock_fd, buffer.data(), buffer.capacity());
        #endif
    }

    ssize_t Networkable::receive(void *buffer, size_t size) const {
        #ifdef __linux__
            return readblock(connection_sock_fd, buffer, size);
        #elif _WIN32
            return r_recv(connection_sock_fd, buffer, size);
        #endif
    }

    #ifdef __linux__
        ssize_t Networkable::dataPending() const {
            ssize_t count = 0;
            if (ioctl(connection_sock_fd, FIONREAD, &count) == -1) {
                char buffer[BUFFER_SIZE];
                strerror_r(errno, buffer, BUFFER_SIZE);
                throw NetworkableException(buffer);
            }

            return count;
        }

        bool Networkable::hasDataPending() const {
            return dataPending() != 0;
        }
    #endif
}
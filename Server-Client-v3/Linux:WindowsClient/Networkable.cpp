//
// Created by Vakhid Betrakhmadov on 03/04/2018.
//

#include "Networkable.h"

namespace  {
    #define BUFFER_SIZE 1024
}

namespace server_client {

    Networkable::Networkable():
                #if defined(__linux__) || defined(__APPLE__)
                    connection_sock_fd(0)
                #elif _WIN32
                    connection_sock_fd(INVALID_SOCKET)
                #endif
                {}

    Networkable::~Networkable() {
        #if defined(__linux__) || defined(__APPLE__)
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
        #if defined(__linux__) || defined(__APPLE__)
            return r_write(connection_sock_fd, (void*) buffer, size);
        #elif _WIN32
            return  r_send(connection_sock_fd, (void*) buffer, size);
        #endif
    }

    ssize_t Networkable::receive(vector<byte> &buffer) const {
        #if defined(__linux__) || defined(__APPLE__)
            return readblock(connection_sock_fd, buffer.data(), buffer.capacity());
        #elif _WIN32
            return r_recv(connection_sock_fd, buffer.data(), buffer.capacity());
        #endif
    }

    ssize_t Networkable::receive(void *buffer, size_t size) const {
        #if defined(__linux__) || defined(__APPLE__)
            return readblock(connection_sock_fd, buffer, size);
        #elif _WIN32
            return r_recv(connection_sock_fd, buffer, size);
        #endif
    }

    ssize_t Networkable::dataPending() const {
        #if defined(__linux__) || defined(__APPLE__)
            ssize_t count = 0;
            if (ioctl(connection_sock_fd, FIONREAD, &count) == -1) {
                char buffer[BUFFER_SIZE];
                strerror_r(errno, buffer, BUFFER_SIZE);
                throw NetworkableException(buffer);
            }
            return count;
        #elif _WIN32
            //TODO: implement
            return 0;
        #endif
    }

    bool Networkable::hasDataPending() const {
        #if defined(__linux__) || defined(__APPLE__)
            return dataPending() != 0;
        #elif _WIN32
            //TODO: implement
            return 0;
        #endif
    }


    int Networkable::send(const Mat& mat) const {
        uint32_t matrixSize = (uint32_t) (mat.total() * mat.elemSize());
        int type = mat.type();

        if (send(&matrixSize, sizeof(uint32_t)) != sizeof(uint32_t))
            return -1;
        else if (send(&mat.rows, sizeof(int)) != sizeof(int))
            return -1;
        else if (send(&mat.cols, sizeof(int)) != sizeof(int))
            return -1;
        else if (send(&type, sizeof(int)) != sizeof(int))
            return -1;
        else if(send(mat.data, matrixSize) != matrixSize)
            return -1;

        return 0;
    }

    int Networkable::receive(Mat& mat) const {
        uint32_t matrixSize = 0;
        int rows = 0;
        int cols = 0;
        int type = 0;

        if(receive(&matrixSize, sizeof(uint32_t)) != sizeof(uint32_t))
            return -1;
        else if(receive(&rows, sizeof(int)) != sizeof(int))
            return -1;
        else if(receive(&cols, sizeof(int)) != sizeof(int))
            return -1;
        else if(receive(&type, sizeof(int)) != sizeof(int))
            return -1;

        mat.create(rows,cols,type);

        if(receive(mat.data, matrixSize) != matrixSize)
            return -1;

        return 0;
    }
}
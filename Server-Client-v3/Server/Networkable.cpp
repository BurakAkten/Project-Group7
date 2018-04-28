//
// Created by Vakhid Betrakhmadov on 03/04/2018.
//

#include "Networkable.h"

namespace  {
    #define BUFFER_SIZE 1024
}

namespace server_client {

    Networkable::Networkable()
            : connection_sock_fd(0) {
    }

    Networkable::~Networkable() {
        r_close(connection_sock_fd);
    }

    ssize_t Networkable::send(const vector<byte>& buffer) const {
        return send(buffer.data(), buffer.size());
    }

    ssize_t Networkable::send(const void* buffer, size_t size) const {
        return r_write(connection_sock_fd, (void*) buffer, size);
    }

    ssize_t Networkable::receive(vector<byte> &buffer) const {
        return readblock(connection_sock_fd, buffer.data(), buffer.capacity());
    }

    ssize_t Networkable::receive(void *buffer, size_t size) const {
        return readblock(connection_sock_fd, buffer, size);
    }

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
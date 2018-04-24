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

//    ssize_t Networkable::r_read_persistent(int fd, void *buf, size_t size) const {
//        char *bufp;
//        size_t bytestoread;
//        ssize_t bytesread;
//        size_t totalbytes;
//
//        for (bufp = (char *) buf, bytestoread = size, totalbytes = 0;
//             bytestoread > 0;
//             bufp += bytesread, bytestoread -= bytesread) {
//            bytesread = read(fd, bufp, bytestoread);
//            if ((bytesread) == -1 && (errno != EINTR))
//                return -1;
//            if (bytesread == -1)
//                bytesread = 0;
//            totalbytes += bytesread;
//        }
//        return totalbytes;
//    }
}
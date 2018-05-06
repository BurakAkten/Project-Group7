//
// Created by vakhidbetrakhmadov on 14/04/2018.
//

#include "wrestart.h"

#if _WIN32

ssize_t r_send(SOCKET s, void* buf, size_t len) {
    char *bufp;
    size_t bytestowrite;
    ssize_t byteswritten;
    size_t totalbytes;

    for (bufp = (char*) buf, bytestowrite = len, totalbytes = 0;
         bytestowrite > 0;
         bufp += byteswritten, bytestowrite -= byteswritten) {
        byteswritten = send(s, bufp, bytestowrite, 0);
        if ((byteswritten) == SOCKET_ERROR && (WSAGetLastError() != WSAEINTR))
            return SOCKET_ERROR;
        if (byteswritten == SOCKET_ERROR)
            byteswritten = 0;
        totalbytes += byteswritten;
    }
    return totalbytes;
}

ssize_t r_recv(SOCKET s, void* buf, size_t len) {
    char *bufp;
    ssize_t bytesread;
    size_t bytestoread;
    size_t totalbytes;

    for (bufp = (char*) buf, bytestoread = len, totalbytes = 0;
         bytestoread > 0;
         bufp += bytesread, bytestoread -= bytesread) {
        bytesread = recv(s, bufp, bytestoread, 0);
        if ((bytesread == 0) && (totalbytes == 0))
            return 0;
        if ((bytesread) == SOCKET_ERROR && (WSAGetLastError() != WSAEINTR))
            return SOCKET_ERROR;
        if (bytesread == SOCKET_ERROR)
            bytesread = 0;
        totalbytes += bytesread;
    }
    return totalbytes;
}

#endif

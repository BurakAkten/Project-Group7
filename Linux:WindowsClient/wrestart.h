//
// Created by vakhidbetrakhmadov on 14/04/2018.
//

#ifndef WRESTART_H
#define WRESTART_H

#ifndef UNICODE
#define UNICODE
#endif

#define WIN32_LEAN_AND_MEAN

#include <winsock2.h>
#include <Ws2tcpip.h>
#include <stdio.h>

// Link with ws2_32.lib
#pragma comment(lib, "Ws2_32.lib")

ssize_t r_send(SOCKET s, void* buf, size_t len);  // return: SOCKET_ERROR or number of bytes sent
ssize_t r_recv(SOCKET s, void* buf, size_t len);  // return: SOCKET_ERROR or number of bytes received

#endif //WRESTART_H

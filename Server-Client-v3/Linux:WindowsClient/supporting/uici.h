#if defined(__linux__) || defined(__APPLE__)

#ifndef UICI_H
#define UICI_H

#include <errno.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <sys/select.h>
#include <sys/socket.h>
#include "uiciname.h"

#ifndef MAXBACKLOG
#define MAXBACKLOG 50
#endif

#define UPORT

#if defined (__cplusplus)
extern "C" {
#endif

typedef unsigned short u_port_t;
int u_open(u_port_t port);
int u_accept(int fd, char *hostn, int hostnsize);
int u_connect(u_port_t port,struct sockaddr_in* server);

#if defined (__cplusplus)
}
#endif

#endif

#endif
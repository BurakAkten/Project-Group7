/* uiciname.h  name resolution functions */
#if defined(__linux__) || defined(__APPLE__)

#ifndef UICINAME_H
#define UICINAME_H

#include <ctype.h>
#include <netdb.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#include <netinet/in.h>
#define REENTRANT_NONE 0
#define REENTRANT_R 1
#define REENTRANT_MUTEX 2
#define REENTRANT_POSIX 3

#if defined (__cplusplus)
extern "C" {
#endif

int name2addr(char *name, in_addr_t *addrp);
void addr2name(struct in_addr addr, char *name, int namelen);
 
#if defined (__cplusplus)
}
#endif

#endif

#endif
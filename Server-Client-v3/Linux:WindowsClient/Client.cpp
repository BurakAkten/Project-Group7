//
// Created by Vakhid Betrakhmadov on 03/04/2018.
//

#include "Client.h"

namespace server_client {

    Client::Client(const string& theHostname, callback_t theCallback)
            : Client(DEFAULT_PORT, theHostname, theCallback) {
    }

    Client::Client(u_port_t thePort, const string& theHostname, callback_t theCallback)
            : port(thePort),
              hostname(theHostname),
              callback(theCallback) {
        sockaddr.sin_port = htons((short) port);
        sockaddr.sin_family = AF_INET;
        #if defined(__linux__) || defined(__APPLE__)
            if (name2addr((char*) hostname.c_str(), &(sockaddr.sin_addr.s_addr)) == -1) {
                std::stringstream message;
                message << "name2addr(): errno = " << errno;
                throw NetworkableException(message.str());
            }
        #elif _WIN32
            sockaddr.sin_addr.s_addr = inet_addr(hostname.c_str());
            if(WSAStartup(MAKEWORD(2,2), &wsaData) != NO_ERROR) {
                std::stringstream message;
                message << "WSAStartup(): error = " << WSAGetLastError();
                throw NetworkableException(message.str());
            }
        #endif
    }

    Client::~Client() {
        #if _WIN32
            WSACleanup();
        #endif
    }

    int Client::connectToServer() {
        #if defined(__linux__) || defined(__APPLE__)
            if ((connection_sock_fd = u_connect(port, &sockaddr)) == -1)
                return -1;
        #elif _WIN32
            if (((connection_sock_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == INVALID_SOCKET)
                || (connect(connection_sock_fd, (SOCKADDR *) &sockaddr, sizeof(sockaddr)) == SOCKET_ERROR))
                return -1;
        #endif
            else
                callback(*this);

        return 0;
    }

    void Client::disconnectFromServer() const {
        #if defined(__linux__) || defined(__APPLE__)
            r_close(connection_sock_fd);
        #elif _WIN32
            shutdown(connection_sock_fd, SD_BOTH);
        #endif
    }
}
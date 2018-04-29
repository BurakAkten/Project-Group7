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
        if (name2addr((char*) hostname.c_str(), &(sockaddr.sin_addr.s_addr)) == -1) {
            std::stringstream message;
            message << "name2addr(): errno = " << errno;
            throw NetworkableException(message.str());
        }
    }

    Client::~Client() {
    }

    int Client::connect() {
        if ((connection_sock_fd = u_connect(port, &sockaddr)) == -1)
            return -1;
        else
            callback(*this);

        return 0;
    }

    void Client::disconnect() const {
        r_close(connection_sock_fd);
    }
}
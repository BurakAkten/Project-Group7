//
// Created by Vakhid Betrakhmadov on 31/03/2018.
//

#include "Server.h"

namespace server_client {

    Server::Server(callback_t theCallback)
            : Server(DEFAULT_PORT,theCallback) {
    }

    Server::Server(u_port_t thePort, callback_t theCallback)
            : Networkable(),
              port(thePort),
              callback(theCallback),
              passive_sock_fd(0),
              stopped(false) {
    }

    Server::~Server() {
        r_close(passive_sock_fd);
    }

    int Server::run() {
        if ((passive_sock_fd = u_open(DEFAULT_PORT)) == -1)
            return -1;

        for(;!stopped;) {
            if((connection_sock_fd = u_accept(passive_sock_fd, nullptr , 0)) == -1) {
                err("u_accept()");
                continue;
            } else {
                callback(*this);
            }
        }

        return 0;
    }

    void Server::stop() {
        stopped = true;
    }
}
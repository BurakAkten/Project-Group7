//
// Created by Vakhid Betrakhmadov on 31/03/2018.
//

#ifndef SERVER_SERVER_H
#define SERVER_SERVER_H

#include "Networkable.h"

namespace server_client {

    class Server;
    typedef void(*callback_t)(Server& server);

    // TODO: Make it singleton
    class Server: public Networkable {
        u_port_t port;
        callback_t callback;
        int passive_sock_fd;
        volatile bool stopped;

    public:
        Server(callback_t theCallback);
        Server(u_port_t port, callback_t theCallback);
        virtual ~Server();
        int run();
        void stop();
    };
}

#endif //SERVER_SERVER_H

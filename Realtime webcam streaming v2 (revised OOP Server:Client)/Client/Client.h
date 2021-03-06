//
// Created by Vakhid Betrakhmadov on 03/04/2018.
//

#ifndef CLIENT_CLIENT_H
#define CLIENT_CLIENT_H

#include <sstream>
#include "Networkable.h"

namespace server_client {

    class Client;
    typedef void(*callback_t)(Client& client);

    class Client: public Networkable {
        u_port_t port;
        string hostname;
        struct sockaddr_in sockaddr;
        callback_t callback;

    public:
        Client(const string& theHostname, callback_t theCallback);
        Client(u_port_t thePort, const string& theHostname, callback_t theCallback);
        virtual ~Client();
        int connect();
    };
}


#endif //CLIENT_CLIENT_H

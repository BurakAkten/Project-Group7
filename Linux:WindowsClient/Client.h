//
// Created by Vakhid Betrakhmadov on 03/04/2018.
//

#ifndef CLIENT_H
#define CLIENT_H

#include <sstream>
#include "Networkable.h"

namespace server_client {

    typedef unsigned short u_port_t;

    class Client;
    typedef void(*callback_t)(Client& client);

    class Client: public Networkable {
        u_port_t port;
        string hostname;
        struct sockaddr_in sockaddr;
        callback_t callback;

        #if _WIN32
            WSADATA wsaData;
        #endif

    public:
        Client(const string& theHostname, callback_t theCallback);
        Client(u_port_t thePort, const string& theHostname, callback_t theCallback);
        virtual ~Client();
        int connectToServer();
        void disconnectFromServer() const;
    };
}

#endif //CLIENT_H

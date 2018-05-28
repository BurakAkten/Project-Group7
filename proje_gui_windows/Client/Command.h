//
// Created by Vakhid Betrakhmadov on 30/04/2018.
//

#ifndef COMMAND_H
#define COMMAND_H

namespace server_client {

    enum class Command: int {
        start = 100 , stop, init_point, no_helmet, none
    };

    ostream& operator << (ostream& out, const Command& command) {
        switch (command) {
            case Command::start: cout << "start"; break;
            case Command::stop: cout << "stop"; break;
            case Command::init_point: cout << "init_point"; break;
            case Command::no_helmet: cout << "no_helmet"; break;
            case Command::none: cout << "none"; break;
        }
        return out;
    }
}

#endif

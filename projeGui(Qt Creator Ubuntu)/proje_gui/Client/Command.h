//
// Created by Vakhid Betrakhmadov on 30/04/2018.
//

#ifndef COMMAND_H
#define COMMAND_H

namespace server_client {

    enum class Command: int {
        start = 100 , stop, database_updated, none
    };

    ostream& operator << (ostream& out, const Command& command) {
        switch (command) {
            case Command::start: cout << "start"; break;
            case Command::stop: cout << "stop"; break;
            case Command::database_updated: cout << "database_updated"; break;
            case Command::none: cout << "none"; break;
        }
        return out;
    }
}

#endif //COMMAND_H

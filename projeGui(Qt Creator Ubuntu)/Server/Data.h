//
// Created by Vakhid Betrakhmadov on 02/05/2018.
//

#ifndef DATA_H
#define DATA_H

namespace server_client {

    struct CriticalArea {
        const int x1;
        const int x2;
        const int y;


        CriticalArea(int theX1, int theX2, int theY)
                : x1(theX1),
                  x2(theX2),
                  y(theY) {
        }

        CriticalArea(): CriticalArea(0,0,0) {
        }
    };
}

#endif //DATA_H

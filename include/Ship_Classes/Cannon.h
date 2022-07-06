//
// Created by artem on 19.04.22.
//

#ifndef MYCOOLGAME_CANNON_H
#define MYCOOLGAME_CANNON_H

#include <ShipObject.h>
#include <CannonBall.h>
#include <ctime>

class Cannon : ShipObject {
public:
    Cannon(Object* ship, Coordinates offset, double angle);
    bool Fire();
private:
    time_t interval = 1;
    time_t last_call;
};

#endif //MYCOOLGAME_CANNON_H

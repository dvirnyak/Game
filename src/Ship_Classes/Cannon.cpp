#include "Cannon.h"

Cannon::Cannon(Object *ship, Coordinates offset, double angle) :
ShipObject("Cannon", ship, offset, angle), last_call(time(NULL)) {
}

bool Cannon::Fire() {
    if (time(NULL) - last_call < interval) {
        return false;
    }
    last_call = time(NULL);

    double absolute = 10000;
    Vector2D force = Vector2D(angle_ + 90, absolute, true);

    new CannonBall(ship_, coordinates_, force);

    return true;
}

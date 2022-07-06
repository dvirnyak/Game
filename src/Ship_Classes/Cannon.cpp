#include "Cannon.h"

Cannon::Cannon(Object *ship, Coordinates offset, double angle) :
ShipObject("Cannon", ship, offset, angle), last_call(time(NULL)) {
}

bool Cannon::Fire() {
    if (time(NULL) - last_call < interval) {
        return false;
    }
    last_call = time(NULL);

    double abs_speed = 200;
    Vector2D speed = Vector2D(angle_ + 90, abs_speed, true);
    speed += ship_->GetSpeed();
    new CannonBall(ship_, coordinates_, speed);

    return true;
}

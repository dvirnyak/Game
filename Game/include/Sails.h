#ifndef MYCOOLGAME_SAILS_H
#define MYCOOLGAME_SAILS_H

#include <ShipObject.h>

class Sails : protected ShipObject {
public:
    Sails(Object* ship, Coordinates offset);
    Vector2D GetForce(Coordinates);
    void Update() override;
};

#endif //MYCOOLGAME_SAILS_H

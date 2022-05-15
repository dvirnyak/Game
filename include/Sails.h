#ifndef MYCOOLGAME_SAILS_H
#define MYCOOLGAME_SAILS_H

#include <ShipObject.h>

class Sails : public ShipObject {
public:
    Sails(Object* ship, const Coordinates& offset);
    ~Sails() = default;
    Vector2D GetForce();
};

#endif //MYCOOLGAME_SAILS_H

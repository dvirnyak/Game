#ifndef MYCOOLGAME_SAILS_H
#define MYCOOLGAME_SAILS_H

#include <ShipObject.h>

class Sails : public ShipObject {
public:
    Sails(Object* ship, const Coordinates& offset);
    Vector2D GetForce();
    void Update() override;
};

#endif //MYCOOLGAME_SAILS_H

//
// Created by artem on 17.04.22.
//

#ifndef MYCOOLGAME_SHIP_H
#define MYCOOLGAME_SHIP_H

#include <Object.h>
#include <Sails.h>
#include <ShipObject.h>

class Ship : public Object {
public:
    Ship(const Coordinates& coordinates, double angle = 0, Vector2D speed = Vector2D(0,0));
    ~Ship();
    void Update() override;

    inline static vector<Ship*> ships;

private:
    int hp_ = 100;
    ShipObject* sails_;
    /*
     * equipment
     * gun
     * hp
     *
     */
};

#endif //MYCOOLGAME_SHIP_H

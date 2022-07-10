//
// Created by artem on 17.04.22.
//

#ifndef MYCOOLGAME_SHIP_H
#define MYCOOLGAME_SHIP_H

#include <Object.h>
#include <Sails.h>
#include <Cannon.h>
#include <ShipObject.h>

class Ship : public Object {
public:
    Ship(const Coordinates& coordinates, double angle = 0, Vector2D speed = Vector2D(0,0));
    ~Ship();
    void Update() override;
    void SetSailsDirection(Vector2D direction);
    void ChangeAngle(double angle_diff);
    void Fire(bool left = true);
    inline static vector<Ship*> ships;
    void Boom();

private:
    int hp_;

    Sails* sails_;
    Cannon* left_cannon_;
    Cannon* right_cannon_;
    /*
     * equipment
     *
     */
};

#endif //MYCOOLGAME_SHIP_H

#ifndef MYCOOLGAME_CANNONBALL_H
#define MYCOOLGAME_CANNONBALL_H

#include <Object.h>

class CannonBall : Object {
public:
    CannonBall(Object* ship, Coordinates start_point, Vector2D speed);
    void Update() override;
private:
    inline static const double g = 9.8;

    double height;
    double speed_y = 0;
    Sizes orignal_sizes_;

    Object* ship_;
};

#endif //MYCOOLGAME_CANNONBALL_H

#ifndef MYCOOLGAME_CANNONBALL_H
#define MYCOOLGAME_CANNONBALL_H

#include <Object.h>

class CannonBall : Object {
public:
    CannonBall(Object* ship, Coordinates start_point, Vector2D force);
    void Update() override;
private:
    inline static const double g = double(9.8);

    double weight_ = 1;

    double height = 0;
    double speed_y = 0;
    Sizes original_sizes_;

    Object* ship_;
};

#endif //MYCOOLGAME_CANNONBALL_H

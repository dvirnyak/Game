#ifndef MYCOOLGAME_CANNONBALL_H
#define MYCOOLGAME_CANNONBALL_H

#include <Object.h>
#include <chrono>

class CannonBall : Object {
public:
    CannonBall(Coordinates start_point, Vector2D speed);
    void Update() override;
private:
    inline static const double g = 9.8;
    std::chrono::milliseconds ms_start;
    double height;
    double speed_y = 0;
    Sizes orignal_sizes_;
};

#endif //MYCOOLGAME_CANNONBALL_H

#include <CannonBall.h>
#include <Game.h>

CannonBall::CannonBall(Coordinates start_point, Vector2D speed) : Object("CannonBall", start_point),
height(0) {
    speed_ = speed;
    speed_y = 50000;
    orignal_sizes_ = sizes_;
}

void CannonBall::Update() {
    speed_y -= g * 1000 / Game::FPS_;
    height += speed_y * 1000 / Game::FPS_;

    if (height <= 0) {
        kill_me_ = true;
    }
    Resize(orignal_sizes_ * (1 + height / 100000000));

    double k = 0.0025 / 500 * Game::FPS_;
    speed_ -= Vector2D(speed_.GetAngle(), k * pow(speed_.GetAbs(), 1.5), true);

    Resize(sizes_ * 1.01);
    Move();

    for (auto ship : Ship::ships) {
        if (Object::Collised(ship, this)) {
            ship->Boom();
            kill_me_ = true;
            break;
        }
    }
}

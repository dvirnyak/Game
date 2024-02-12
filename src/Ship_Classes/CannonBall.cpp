#include <CannonBall.h>
#include <Game.h>

CannonBall::CannonBall(Object* ship, Coordinates start_point, Vector2D force) :
Object("CannonBall", start_point, 0, {0, 0}, 1), ship_(ship), height(2) {

    speed_ = ship_->GetSpeed();
    PushWithForce(force);

    ship_->PushWithForce(force * -1);

    speed_y = ((force.GetDist() / weight_) * Game::dt) / 10;

    original_sizes_ = sizes_;
}

void CannonBall::Update() {

    speed_y -= g * Game::dt;
    height += speed_y * Game::dt;

    if (height <= 0) {
        kill_me_ = true;
    }

    Resize(original_sizes_ * (1 + (height - 7) / 7));

    double k = 0.0025 * Game::dt;
    speed_ -= Vector2D(speed_.GetAngle(), k * pow(speed_.GetAbs(), 1.5), true);

    Drift();

    for (auto ship : Ship::ships) {
        if (Object::Collised(ship, this) && ship != ship_) {
            ship->Boom();
            kill_me_ = true;
            break;
        }
    }
}

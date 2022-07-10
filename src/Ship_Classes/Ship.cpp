#include "Ship.h"
#include "Map.h"
#include "Game.h"

Ship::Ship(const Coordinates& coordinates, double angle_, Vector2D speed) :
Object("Ship", coordinates, 0, speed, 300), hp_(100) {

    left_cannon_ = new Cannon(this, Coordinates(-35, -20), -180);
    right_cannon_ = new Cannon(this, Coordinates(-35, 20), -0);
    sails_ = new Sails(this, Coordinates(10, 0));
    MoveByDirection(Vector2D(0,0), angle_);

    ships.push_back(this);
};

Ship::~Ship() {
    delete sails_;
    delete left_cannon_;
    delete right_cannon_;

    auto itr = ships.begin();
    while (itr != ships.end() && ships.size() > 0) {
        if ((*itr) == this) {
            ships.erase(itr);
            break;
        } else {
            ++itr;
        }
    }
}

void Ship::Update() {
    // 5% per second
    speed_ *= DiffPercentPerSecond(-10);

    PushWithForce(sails_->GetForce());
    Drift();

    if (hp_ <= 0) {
        kill_me_ = true;
    }
}

void Ship::SetSailsDirection(Vector2D direction) {
    sails_->SetDirection(direction);
}

void Ship::ChangeAngle(double angle_diff) {
    angle_ += angle_diff;
    angle_ = Vector2D::normaliseAngle(angle_);
    speed_.Rotate(angle_diff);
    speed_ *= DiffPercentPerSecond(-5);
}



void Ship::Fire(bool left) {
    if (left) {
        left_cannon_->Fire();
    } else {
        right_cannon_->Fire();
    }
}

void Ship::Boom() {
    hp_ -= 50;
}

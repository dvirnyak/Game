#include "Ship.h"
#include "Map.h"

Ship::Ship(const Coordinates& coordinates, double angle_, Vector2D speed) :
Object("Ship", coordinates, 0, speed) {
    left_cannon_ = new Cannon(this, Coordinates(-35, -20), -180);
    right_cannon_ = new Cannon(this, Coordinates(-35, 20), -0);
    sails_ = new Sails(this, Coordinates(10, 0));
    Move(Vector2D(0,0), angle_);

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
    double weight = 15000;
    speed_ *= 0.995;
    speed_ += sails_->GetForce() * (1 / weight);
    Coordinates before = coordinates_;
    Move();
    if (!Map::inMap(coordinates_)) {
        speed_ *= -1;
        coordinates_ = before;
    }
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
    speed_ *= 0.98;
}

void Ship::Fire(bool left) {
    if (left && left_cannon_->Fire()) {
        speed_ += Vector2D(angle_ + 90, 10, bool());
    } else if (!left && right_cannon_->Fire()) {
        speed_ += Vector2D(angle_ - 90, 10, bool());
    }
}

void Ship::Boom() {
    hp_ -= 50;
}

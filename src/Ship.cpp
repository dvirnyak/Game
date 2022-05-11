#include "Ship.h"
#include "Map.h"

Ship::Ship(const Coordinates& coordinates, double angle_, Vector2D speed) :
Object("Ship", coordinates, 0, speed) {
    GetImage()->center += Coordinates(0, 0);
    Coordinates offset(0, -15);

    sails_ = new Sails(this, offset);
    Move(Vector2D(0,0), angle_);
};

Ship::~Ship() {
    delete sails_;
}

void Ship::Update() {
    double weight = 3;
    speed_ = sails_->GetForce() * (1 / weight);
    Coordinates before = coordinates_;
    Move();
    if (!Map::inMap(coordinates_)) {
        speed_ *= -1;
        coordinates_ = before;
    }
}

void Ship::SetSailsDirection(Vector2D direction) {
    sails_->SetDirection(direction);
}

void Ship::ChangeAngle(double angle_diff) {
    angle_ += angle_diff;
    angle_ = Vector2D::normaliseAngle(angle_);
}

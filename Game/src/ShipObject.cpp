#include "ShipObject.h"

ShipObject::ShipObject(string type, Object* ship, Coordinates offset) :
        Object(type, ship->GetCoordinates() + offset,
               ship->GetAngle()),
        ship_(ship),
        coordinatesOffset_(offset),
        angleOffset_(0) {
}

void ShipObject::FollowShip() {
    angle_ = ship_->GetAngle() + angleOffset_;
    MoveTo(ship_->GetCoordinates() + Vector2D(coordinatesOffset_, ship_->GetAngle()),
           angle_);
    //std::cout << GetCoordinates().x << " " << GetCoordinates().y << "\n";
}

void ShipObject::Update() {
    FollowShip();
}

void ShipObject::SetDirection(Vector2D direction) {
    angleOffset_ = Vector2D::normaliseAngle(direction.GetAngle() - ship_->GetAngle());
    if (angleOffset_ > 40) {
        if (angleOffset_ < 180) {
            angleOffset_ = 40;
        } else if (angleOffset_ < 320) {
            angleOffset_ = 320;
        }
    }
}

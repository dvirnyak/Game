#include "ShipObject.h"

ShipObject::ShipObject(string type, Object* ship, Coordinates offset, double angle) :
        Object(type, ship->GetCoordinates() + offset,
               ship->GetAngle() + angle),
        ship_(ship),
        coordinatesOffset_(offset),
        angleOffset_(angle) {
}

void ShipObject::FollowShip() {
    angle_ = ship_->GetAngle() + angleOffset_;
    SetPosition(ship_->GetCoordinates() + Vector2D(coordinatesOffset_, ship_->GetAngle()),
           angle_);
}

void ShipObject::Update() {
    FollowShip();
}

void ShipObject::SetDirection(Vector2D direction) {
    angleOffset_ = Vector2D::normaliseAngle(direction.GetAngle() - ship_->GetAngle());
    if (angleOffset_ < -40) {
        angleOffset_ = -40;
    } else if (angleOffset_ > 40) {
        angleOffset_ = 40;
    }
}

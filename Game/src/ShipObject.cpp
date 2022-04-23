#include "ShipObject.h"

ShipObject::ShipObject(string type, Object* ship, Coordinates offset) :
        Object(type, ship->GetCoordinates() + offset,
               ship->GetAngle()),
        ship_(ship),
        coordinatesOffset_(offset),
        angleOffset_(0) {
}

void ShipObject::FollowShip() {
    MoveTo(ship_->GetCoordinates() + Vector2D(coordinatesOffset_, ship_->GetAngle()),
           ship_->GetAngle() + angleOffset_);
    //std::cout << GetCoordinates().x << " " << GetCoordinates().y << "\n";
}

void ShipObject::Update() {
    FollowShip();
}
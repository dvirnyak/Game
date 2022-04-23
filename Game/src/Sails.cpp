#include "Sails.h"

Sails::Sails(Object* ship, Coordinates offset) :
ShipObject("Sails", ship, offset) {
}

Vector2D Sails::GetForce(Coordinates) {
    double absolute = 10;
    return Vector2D(ship_->GetAngle(), absolute);
}

void Sails::Update() {
    FollowShip();
    //std::cout << GetCoordinates().x << " " << GetCoordinates().y << "\n";
}

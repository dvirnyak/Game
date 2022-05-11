#include "Sails.h"
#include "Map.h"
#include <cmath>

Sails::Sails(Object* ship, const Coordinates& offset) :
ShipObject("Sails", ship, offset) {
}

Vector2D Sails::GetForce() {
    Vector2D wind = Map::GetWind(ship_->GetCoordinates());
    double diff_angle = wind.GetAngle() - angle_;
    diff_angle = Vector2D::normaliseAngle(diff_angle);
    double absolute = wind.GetAbs() * cos(diff_angle * 3.1415 / 180);

    if (absolute < 0) {
        absolute *= 0.1;
    }
    return Vector2D(ship_->GetAngle(), absolute, true);
}

void Sails::Update() {
    FollowShip();
    //std::cout << GetCoordinates().x << " " << GetCoordinates().y << "\n";
}



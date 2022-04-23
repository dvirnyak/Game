#include "Ship.h"

Ship::Ship(const Coordinates& coordinates, double angle_, Vector2D speed) :
Object("Ship", coordinates, 0, speed) {
    GetImage()->center += Coordinates(0, 0);
    Coordinates offset(0, -15);

    sails_ = new ShipObject("Sails", this, offset);
    Move(Vector2D(0,0), angle_);
    //ships.push_back(this);
};

Ship::~Ship() {
    delete sails_;
    auto itr = ships.begin();
    while (itr != ships.end() && ships.size() > 0) {
        if ((*itr) == this) {
            itr = ships.erase(itr);
            break;
        } else {
            ++itr;
        }
    }
    std::cout << "~Ship\n";
}

void Ship::Update() {
    Move();
    //image_->Update();
}
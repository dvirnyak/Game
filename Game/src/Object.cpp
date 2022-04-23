#include "Object.h"
#include "Game.h"

Object::Object(string type, const Coordinates& coordinates, double angle, Vector2D speed,
               Coordinates center) :
type_(type), coordinates_(coordinates), angle_(angle), speed_(speed) {
    string source = dirAssets + typeImageSources_[type];
    image_ = new Image(source, coordinates_, sizes_, angle_, center);

    objects.push_back(this);
};

Object::~Object() {
    std::cout << "delete\n";
    auto itr = objects.begin();
    while (itr != objects.end() && objects.size() > 0) {
        if ((*itr) == this) {
            itr = objects.erase(itr);
            break;
        } else {
            ++itr;
        }
    }
    delete image_;
}

void Object::Move() {
    coordinates_ += speed_ * (double(1) / Game::FPS_);
    image_->Update(coordinates_, sizes_, angle_);
}

void Object::Move(Vector2D vec, double angle) {
    coordinates_ += vec;
    angle_ += angle;
    image_->Update(coordinates_, sizes_, angle_);
}

void Object::MoveTo(Coordinates vec, double angle) {
    coordinates_ = vec;
    angle_ = angle;
    image_->Update(coordinates_, sizes_, angle_);
}

void Object::Update() {
    Move();
    image_->Update(coordinates_, sizes_, angle_);
}

Image* Object::GetImage() {
    return image_;
}

Coordinates Object::GetCoordinates() const {
    return coordinates_;
};

double Object::GetAngle() {
    return angle_;
};

void Object::Clean() {
    auto itr = objects.begin();
    while (itr != objects.end() && objects.size() > 0) {
        itr = objects.erase(itr);
    }
}

Object::operator Coordinates() {
    return coordinates_;
}

map<string, string> Object::typeImageSources_ = {
        {"Ship", "ship2.bmp"},
        {"Sails", "sails.bmp"}
};

map<string, Sizes> Object::typeDefaultSizes_ = {
        {"Ship", Sizes(414, 178) * 0.5},
        {"Sails", Sizes(58, 249) * 0.6}
};
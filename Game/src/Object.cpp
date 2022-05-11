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
    std::cout << type_ << "\n";
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
    Coordinates before = coordinates_;
    Move();
    if (!Map::inMap(coordinates_)) {
        speed_ *= -1;
        coordinates_ = before;
    }
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
        delete *itr;
    }
}

Object::operator Coordinates() {
    return coordinates_;
}

map<string, string> Object::typeImageSources_ = {
        {"Ship", "ship2.bmp"},
        {"Sails", "sails.bmp"},
        {"Island", "island1.bmp"},
        {"Arrow", "arrow.bmp"}
};

map<string, Sizes> Object::typeDefaultSizes_ = {
        {"Ship", Sizes(414, 178) * 0.5},
        {"Sails", Sizes(58, 249) * 0.6},
        {"Island", Sizes(300, 300) * 1.5},
        {"Arrow", Sizes(25, 70)}
};
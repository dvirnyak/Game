#include "Object.h"
#include "Game.h"

Object::Object(string type, const Coordinates& coordinates,
               double angle, Vector2D speed, double weight) :
type_(type), coordinates_(coordinates), angle_(angle),
speed_(speed), weight_(weight), sizes_(TypeDefaultSizes[type_]) {

    string source = dirAssets + TypeImageSources[type];
    image_ = new Image(source, coordinates_, sizes_, angle_);

    objects.push_back(this);
}

Object::~Object() {
    delete image_;

    auto itr = objects.begin();
    while (itr != objects.end() && objects.size() > 0) {
        if ((*itr) == this) {
            objects.erase(itr);
            break;
        } else {
            ++itr;
        }
    }

}

void Object::Drift() {
    Coordinates before = coordinates_;

    coordinates_ += speed_ * Game::dt;

    if (!Map::inMap(coordinates_)) {
        speed_ *= -1;
        coordinates_ = before;
    }

    image_->Update(coordinates_, sizes_, angle_);
}

void Object::PushWithForce(Vector2D force) {
    speed_ += (force * (double(1) / weight_)) * Game::dt;
}

void Object::MoveByDirection(Vector2D vec, double angle) {
    coordinates_ += vec;
    angle_ += angle;
    image_->Update(coordinates_, sizes_, angle_);
}

void Object::SetPosition(const Coordinates& point, double angle) {
    coordinates_ = point;
    angle_ = angle;
    image_->Update(coordinates_, sizes_, angle_);
}

void Object::Update() {
    Coordinates before = coordinates_;
    Drift();

    if (!Map::inMap(coordinates_)) {
        speed_ *= -1;
        coordinates_ = before;
    }

    image_->Update(coordinates_, sizes_, angle_);
}

Image* Object::GetImage() const {
    return image_;
}

Coordinates Object::GetCoordinates() const {
    return coordinates_;
};

double Object::GetAngle() const {
    return angle_;
};

Vector2D Object::GetSpeed() const {
    return speed_;
}

void Object::Resize(Sizes new_sizes) {
    sizes_ = new_sizes;
    image_->Update(coordinates_, sizes_, angle_);
}

void Object::Draw() {
    image_->Draw();
}

void Object::Clean() {
    auto itr = objects.begin();
    while (itr != objects.end() && objects.size() > 0) {
        delete *itr;
    }
}

void Object::DeleteKilled() {
    auto itr = objects.begin();
    while (itr != objects.end() && objects.size() > 0) {
        if ((*itr)->kill_me_) {
            delete *itr;
            itr = objects.begin();
        } else {
            ++itr;
        }
    }
}

// not implemented outdated realisation

/* void Object::CheckCollisions() {
    if (time(NULL) - last_call_collisions < interval_collisions) {
        return;
    }
    last_call_collisions = time(NULL);
    for (auto obj1 : objects) {
        for (auto obj2 : objects) {
            if (obj1 != obj2 && Collised(obj1, obj2)
            || Collised(obj2, obj1)) {
                //obj1->kill_me_ = true;
                //obj2->kill_me_ = true;
                std::cout << "collised\n";
            }
        }
    }
}
*/

bool Object::Collised(Object* a, Object* b) {
    double diff_angle = a->angle_ - b->angle_;

    Coordinates coordinates_a = a->coordinates_;
    Coordinates coordinates_b = b->coordinates_;
    coordinates_a = Vector2D(coordinates_a).Rotate(-b->angle_);
    coordinates_b = Vector2D(coordinates_b).Rotate(-b->angle_);

    Coordinates points[4];
    points[0] = coordinates_a;
    points[1] = coordinates_a +
                Vector2D(Coordinates(a->sizes_.width, 0)).Rotate(diff_angle);
    points[2] = coordinates_a +
                Vector2D(Coordinates(0, a->sizes_.height)).Rotate(diff_angle);
    points[3] = coordinates_a +
                Vector2D(Coordinates(a->sizes_.width,a->sizes_.height)).Rotate(diff_angle);

    for (const Coordinates& point : points) {
        if (point.x >= coordinates_b.x
            && point.x <= coordinates_b.x + b->sizes_.width
            && point.y >= coordinates_b.y
            && point.y <= coordinates_b.y + b->sizes_.height)
            return true;
    }

    return false;
}

map<string, string> Object::TypeImageSources = {
        {"Ship", "Ship.bmp"},
        {"Sails", "Sails.bmp"},
        {"Island", "Island.bmp"},
        {"Arrow", "Arrow.bmp"},
        {"Cannon", "Cannon.bmp"},
        {"CannonBall", "CannonBall.bmp"}
};

map<string, Sizes> Object::TypeDefaultSizes = {
        {"Ship", Sizes( 178, 414) * 0.5},
        {"Sails", Sizes(249, 58) * 0.6},
        {"Island", Sizes(300, 300) * 1.5},
        {"Arrow", Sizes(70, 25)},
        {"Cannon", Sizes(30, 50)},
        {"CannonBall", Sizes(20, 20)}
};

double Object::DiffPercentPerSecond(double percent) {
    return double(1) + (percent / 100 * Game::dt);
}













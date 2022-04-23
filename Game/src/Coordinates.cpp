#include <Coordinates.h>

Coordinates::Coordinates(double xpos, double ypos) : x(xpos), y(ypos) {
};


Coordinates& Coordinates::operator +=(const Coordinates& point) {
    x += point.x;
    y += point.y;
    return *this;
}

Coordinates& Coordinates::operator -=(const Coordinates& point) {
    x -= point.x;
    y -= point.y;
    return *this;
}

Coordinates Coordinates::operator +(const Coordinates& point) const {
    Coordinates copy = *this;
    return copy += point;
}

Coordinates Coordinates::operator -(const Coordinates& point) const {
    Coordinates copy = *this;
    return copy -= point;
}

Coordinates& Coordinates::operator *=(const double k) {
    x *= k;
    y *= k;
    return *this;
}

Coordinates Coordinates::operator *(const double k) const {
    Coordinates copy = *this;
    return copy *= k;
}

bool Coordinates::operator ==(const Coordinates& point) const {
    return point.x == x && point.y == y;
}

void Coordinates::SetPoint(double new_x, double new_y) {
    x = new_x;
    y = new_y;
}

#include "Vector2D.h"
#include <cmath>
#define PI 3.14159265

Vector2D::Vector2D(Coordinates coordinates) : Coordinates(coordinates.x, -coordinates.y) {
}

Vector2D::Vector2D(Coordinates coordinates, double angle) : Coordinates(coordinates.x, -coordinates.y) {
    Rotate(angle);
}

Vector2D::Vector2D(double angle, double abs, bool flag) {
    x = cos( angle * PI / 180.0 ) * abs;
    y = sin( angle * PI / 180.0 ) * abs;
}

Vector2D::Vector2D(double x, double y) : Vector2D(Coordinates(x, y)) {
}

void Vector2D::Rotate(double angle) {
    *this = Vector2D(GetAngle() + angle, GetAbs(), true);
}

double Vector2D::GetAngle() {
    return atan2 (y, x) * 180.0 / PI;
}

double Vector2D::GetAbs() {
    return sqrt(x*x + y*y);
}
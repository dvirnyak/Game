#ifndef MYCOOLGAME_VECTOR2D_H
#define MYCOOLGAME_VECTOR2D_H

#include <Coordinates.h>

struct Vector2D : public Coordinates {
public:
    Vector2D() = default;
    Vector2D(Coordinates coordinates);
    Vector2D(double angle, double abs, bool flag);
    Vector2D(double x, double y);
    Vector2D(Coordinates coordinates, double angle);
    void Rotate(double angle);
    double GetAngle();
    double GetAbs();
    static float normaliseAngle(double angle);
};

#endif //MYCOOLGAME_VECTOR2D_H

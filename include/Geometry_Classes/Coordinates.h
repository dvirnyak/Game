#ifndef MYCOOLGAME_COORDINATES_H
#define MYCOOLGAME_COORDINATES_H

#include <iostream>
#include <cmath>

struct Coordinates {
    double x = 0;
    double y = 0;

    Coordinates(double x, double y);
    Coordinates() = default;
    Coordinates(const Coordinates& coordinates) = default;
    ~Coordinates() = default;

    Coordinates& operator +=(const Coordinates& point);
    Coordinates& operator -=(const Coordinates& point);
    Coordinates& operator *=(double k);
    Coordinates& operator /=(double k);

    Coordinates operator +(const Coordinates& point) const;
    Coordinates operator -(const Coordinates& point) const;
    Coordinates operator *(double k) const;
    Coordinates& operator /(double k) const;

    bool operator ==(const Coordinates& point) const;

    void SetPoint(double new_x, double new_y);

    double GetDist(const Coordinates& point = {0,0}) const;
};

std::ostream& operator << (std::ostream& out, const Coordinates& coordinates);

#endif //MYCOOLGAME_COORDINATES_H

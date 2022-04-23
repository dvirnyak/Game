#ifndef MYCOOLGAME_COORDINATES_H
#define MYCOOLGAME_COORDINATES_H

struct Coordinates {
    double x = 0;
    double y = 0;
    Coordinates(double x, double y);
    Coordinates() = default;
    Coordinates(const Coordinates& coordinates) = default;
    ~Coordinates() {};
    Coordinates& operator +=(const Coordinates& point);
    Coordinates& operator -=(const Coordinates& point);
    Coordinates operator +(const Coordinates& point) const;
    Coordinates operator -(const Coordinates& point) const;
    Coordinates& operator *=(double k);
    Coordinates operator *(double k) const;
    bool operator ==(const Coordinates& point) const;
    void SetPoint(double new_x, double new_y);
};


#endif //MYCOOLGAME_COORDINATES_H

#ifndef MYCOOLGAME_IMAGE_H
#define MYCOOLGAME_IMAGE_H

#include <string>
#include <Coordinates.h>
#include <Sizes.h>

using std::string;

struct Image {
    Image(string source, Coordinates coordinates, Sizes sizes,
          double angle = 0, Coordinates center = Coordinates(0,0));
    ~Image();
    void Update(Coordinates coordinates, Sizes sizes, double angle = 0);
    void Draw();
    static void SetViewPoint(const Coordinates viewPoint, const double angle = 0);
    static void SetViewPoint(const Coordinates playerCoordinates, const Coordinates center,
                             const double angle = 0);
    static void Zoom(double k);
    static void SetZoom(double k);

    string source;
    Coordinates coordinates;
    Sizes sizes;
    double angle;
    inline static Coordinates center;
private:
    inline static double zoom_ = 1;
    inline static Coordinates viewPoint_ = Coordinates();
    inline static double viewAngle_;
};

#endif //MYCOOLGAME_IMAGE_H

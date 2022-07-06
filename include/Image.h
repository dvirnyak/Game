#ifndef MYCOOLGAME_IMAGE_H
#define MYCOOLGAME_IMAGE_H

#include <string>
#include <Coordinates.h>
#include <Sizes.h>

using std::string;

struct Image {
    Image(string source, Coordinates coordinates, Sizes sizes,
          double angle = 0);

    Image(Coordinates coordinates, Sizes sizes);

    ~Image();
    void Update(Coordinates coordinates, Sizes sizes, double angle = 0);
    void Draw();
    void FixPosition();
    void SetColor(int x, int y, int r, int g, int b, int a);

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
    bool fixed_ = false;
    inline static double zoom_ = 1;
    inline static Coordinates viewPoint_ = Coordinates();
    inline static double viewAngle_;
};

#endif //MYCOOLGAME_IMAGE_H

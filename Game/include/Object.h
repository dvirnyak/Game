#ifndef MYCOOLGAME_OBJECT_H
#define MYCOOLGAME_OBJECT_H

#include <Image.h>
#include <map>
#include <vector>
#include <iostream>
#include <Vector2D.h>

using std::map;
using std::vector;

class Object {
public:
    Object(string type, const Coordinates& coordinates,
           double angle = 0, Vector2D speed = Vector2D(0,0),
           Coordinates center = Coordinates(0,0));
    virtual ~Object();

    void Move();
    void Move(Vector2D vec, double angle = 0);
    void MoveTo(Coordinates vec, double angle = 0);
    virtual void Update();
    Image* GetImage();
    Coordinates GetCoordinates() const;
    double GetAngle();
    static void Clean();

    operator Coordinates();

    inline static vector<Object*> objects;

private:
    Object() = default;
    string type_;
    //all the sources and sizes of types should be in a one place
    inline static string dirAssets = "../assets/";
    static map<string, string> typeImageSources_;
    static map<string, Sizes> typeDefaultSizes_;

protected:
    Coordinates coordinates_;
    Sizes sizes_ = typeDefaultSizes_[type_];
    Vector2D speed_;
    Image* image_;
    double angle_;
};

#endif //MYCOOLGAME_OBJECT_H

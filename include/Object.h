#ifndef MYCOOLGAME_OBJECT_H
#define MYCOOLGAME_OBJECT_H

#include <Image.h>
#include <map>
#include <vector>
#include <iostream>
#include <Geometry.h>

using std::map;
using std::vector;

class Object {
public:
    Object(string type, const Coordinates& coordinates,
           double angle = 0, Vector2D speed = Vector2D(0,0), double weight = 0);
    Object() = delete;
    virtual ~Object();

    void Drift();
    void PushWithForce(Vector2D force);
    void MoveByDirection(Vector2D vec, double angle = 0);
    void SetPosition(const Coordinates& point, double angle = 0);

    virtual void Update();

    Image* GetImage() const;
    Coordinates GetCoordinates() const;
    double GetAngle() const;
    Vector2D GetSpeed() const;

    void Resize(Sizes new_sizes);
    void Draw();

    static void Clean();
    static void DeleteKilled();
    static void CheckCollisions();
    static bool Collised(Object* a, Object* b);

    inline static vector<Object*> objects;

private:

    string type_; // TODO


    inline static time_t interval_collisions = 1;
    inline static time_t last_call_collisions;

    //all the sources and sizes of types should be in a one place
    inline static string dirAssets = "../assets/";
    static map<string, string> TypeImageSources;
    static map<string, Sizes> TypeDefaultSizes;

protected:

    Coordinates coordinates_;
    Sizes sizes_;
    Vector2D speed_;
    double weight_;
    Image* image_;
    double angle_;
    bool kill_me_ = false;

    static double DiffPercentPerSecond(double percent);
};

#endif //MYCOOLGAME_OBJECT_H

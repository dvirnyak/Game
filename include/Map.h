#ifndef MYCOOLGAME_MAP_H
#define MYCOOLGAME_MAP_H

#include <Vector2D.h>
#include <Sizes.h>
#include <Image.h>
#include <deque>
#include <vector>
#include <Object.h>
#include <ctime>

using std::deque;
using std::vector;

struct Cell {
    ~Cell() = default;
    Vector2D wind;
    double pressure = 0;
    double height = 0;
    vector<Object*> objects;
};

class Map {
public:
    Map(Sizes sizes, Coordinates center);
    ~Map();
    static Vector2D GetWind(Coordinates coordinates);
    void Draw();
    void Update();
    static bool inMap(Coordinates coordinates);

private:
    inline static int block_size = 2000;
    Image* img_;
    inline static Coordinates center_;
    inline static Sizes sizes_;
    inline static deque<deque<Cell*>> map_;
    inline static const time_t interval = 5;
    time_t last_update;
};

#endif //MYCOOLGAME_MAP_H

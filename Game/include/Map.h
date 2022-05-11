#ifndef MYCOOLGAME_MAP_H
#define MYCOOLGAME_MAP_H

#include <Vector2D.h>
#include <Sizes.h>
#include <Image.h>
#include <deque>

using std::deque;

struct Cell {
    Vector2D wind;
    double pressure = 0;
    double height = 0;
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
    inline static int block_size = 500;
    Image* img_;
    inline static Coordinates center_;
    inline static Sizes sizes_;
    inline static deque<deque<Cell*>> map_;
    int update_count_ = 0;
};

#endif //MYCOOLGAME_MAP_H

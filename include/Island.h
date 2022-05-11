#ifndef MYCOOLGAME_ISLAND_H
#define MYCOOLGAME_ISLAND_H

#include <Object.h>

class Island : Object {
public:
    Island(Coordinates coordinates, double angle = 0);
    ~Island() = default;
};

#endif //MYCOOLGAME_ISLAND_H

#ifndef MYCOOLGAME_ISLAND_H
#define MYCOOLGAME_ISLAND_H

#include <Object.h>

class Island : public Object {
public:
    Island(Coordinates coordinates, double angle = 0);
    ~Island() = default;
    void Update() override;
};

#endif //MYCOOLGAME_ISLAND_H

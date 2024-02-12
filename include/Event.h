#ifndef MYCOOLGAME_EVENT_H
#define MYCOOLGAME_EVENT_H

#include <Geometry.h>
#include <string>

using std::string;

struct Event {
    Event(string type, Coordinates coordinates = Coordinates(0,0),
          bool KeyLeftPressed = false, bool KeyRightPressed = false,
          bool FireRight = false, bool FireLeft = false);
    Event() = default;
    string type;
    bool KeyLeftPressed;
    bool KeyRightPressed;
    bool FireRight;
    bool FireLeft;
    Coordinates coordinates;
};

#endif //MYCOOLGAME_EVENT_H

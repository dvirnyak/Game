#ifndef MYCOOLGAME_EVENT_H
#define MYCOOLGAME_EVENT_H

#include <Coordinates.h>
#include <string>

using std::string;

struct Event {
    Event(string type, Coordinates coordinates = Coordinates(0,0),
          bool KeyLeftPressed = false, bool KeyRightPressed = false);
    Event() = default;
    ~Event();
    string type;
    bool KeyLeftPressed;
    bool KeyRightPressed;
    Coordinates coordinates;
};

#endif //MYCOOLGAME_EVENT_H

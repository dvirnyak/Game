#ifndef MYCOOLGAME_EVENT_H
#define MYCOOLGAME_EVENT_H

#include <Coordinates.h>
#include <string>

using std::string;

struct Event {
    Event(string type, Coordinates coordinates = Coordinates(0,0));
    Event() = default;
    ~Event();
    string type;
    Coordinates coordinates;
};

/*struct EventQuit : public Event {
    EventQuit();

};

struct EventMouseMove : public Event {
    EventMouseMove(Coordinates coordinates);
    Coordinates coordinates;
};

struct EventClick : public Event {
    EventClick();
    bool pressed;
    Coordinates coordinates;
};

struct EventKeyboard : public Event {
    EventKeyboard();
    char symbol;
};*/

#endif //MYCOOLGAME_EVENT_H

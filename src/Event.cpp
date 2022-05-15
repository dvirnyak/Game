#include <Event.h>
#include <iostream>

Event::Event(string type, Coordinates coordinates,
             bool KeyLeftPressed, bool KeyRightPressed, bool FireRight, bool FireLeft) :
type(type), coordinates(coordinates),
KeyLeftPressed(KeyLeftPressed), KeyRightPressed(KeyRightPressed),
FireLeft(FireLeft), FireRight(FireRight) {
}


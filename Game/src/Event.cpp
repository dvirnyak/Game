#include <Event.h>
#include <iostream>

Event::Event(string type, Coordinates coordinates,
             bool KeyLeftPressed, bool KeyRightPressed) :
type(type), coordinates(coordinates),
KeyLeftPressed(KeyLeftPressed), KeyRightPressed(KeyRightPressed) {
}

Event::~Event() {

}
/*EventQuit::EventQuit() : Event("Quit") {
}

EventQuit::~EventQuit() {

}

EventMouseMove::EventMouseMove(Coordinates coordinates) :
Event("MouseMove"), coordinates(coordinates) {
}
*/


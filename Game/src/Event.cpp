#include <Event.h>
#include <iostream>

Event::Event(string type, Coordinates coordinates) :
type(type), coordinates(coordinates) {
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


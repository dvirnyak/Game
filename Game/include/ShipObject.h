#ifndef MYCOOLGAME_SHIPOBJECT_H
#define MYCOOLGAME_SHIPOBJECT_H

#include <Object.h>

class ShipObject : public Object {
public:
    ShipObject(string type, Object* ship, Coordinates offset);
    void FollowShip();
    virtual void Update();
protected:
    Object* ship_;
    double angleOffset_;
private:
    Coordinates coordinatesOffset_;
};

#endif //MYCOOLGAME_SHIPOBJECT_H

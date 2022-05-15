#ifndef MYCOOLGAME_SHIPOBJECT_H
#define MYCOOLGAME_SHIPOBJECT_H

#include <Object.h>

class ShipObject : public Object {
public:
    ShipObject(string type, Object* ship, Coordinates offset, double angle = 0);
    void FollowShip();
    virtual void Update();
    void SetDirection(Vector2D direction);
protected:
    Object* ship_;
    double angleOffset_;
private:
    Coordinates coordinatesOffset_;
};

#endif //MYCOOLGAME_SHIPOBJECT_H

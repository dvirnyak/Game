#ifndef MYCOOLGAME_INTERFACE_H
#define MYCOOLGAME_INTERFACE_H

#include <Image.h>
#include <Event.h>

class Interface {
public:
    Interface() = default;
    virtual ~Interface() {};
    virtual bool Init(const char* Title, int width, int height, bool fullscreen, int FPS) = 0;
    virtual Event HandleEvents() = 0;
    virtual void ClearScreen() = 0;
    virtual void PresentScreen() = 0;
    virtual void Clean() = 0;

    virtual void LoadImage(Image* img) = 0;
    virtual void RenderImage(Image* img) = 0;
    virtual void DeleteImage(Image* img) = 0;
};

#endif //MYCOOLGAME_INTERFACE_H

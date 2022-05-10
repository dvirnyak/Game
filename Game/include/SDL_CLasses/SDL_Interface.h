#ifndef MYCOOLGAME_SDL_INTERFACE_H
#define MYCOOLGAME_SDL_INTERFACE_H

#include <GameObject.h>
#include <Game_Classes.h>

class SDL_Interface : public Interface {
public:
    SDL_Interface();
    ~SDL_Interface() override;
    bool Init(const char* Title, int width, int height, bool fullscreen, int FPS) override;
    Event HandleEvents() override;
    void ClearScreen() override;
    void PresentScreen() override;
    void Clean() override;

    void LoadImage(Image* img) override;
    void RenderImage(Image* img) override;
    void DeleteImage(Image* img) override;
    void PutPixel(Image* image, int x, int y, int r, int g, int b, int a) override;
    static SDL_Renderer* renderer;
private:
    SDL_Window* window;

    uint32_t frameStart_;
    uint32_t frameDelay_;

    inline static map<Image*, GameObject*> ImageToGameObject;


};


#endif //MYCOOLGAME_SDL_INTERFACE_H

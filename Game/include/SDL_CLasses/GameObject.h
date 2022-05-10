#ifndef MYCOOLGAME_GAMEOBJECT_H
#define MYCOOLGAME_GAMEOBJECT_H

#include <Game_Classes.h>
#include <TextureManager.h>

class GameObject {
public:
    GameObject(Image* img);
    GameObject();
    ~GameObject();
    void Render();
    void SetPixel(int x, int y, int r, int g, int b, int a);
private:
    Image* img_;

    SDL_Texture* objTexture;

};

#endif //MYCOOLGAME_GAMEOBJECT_H

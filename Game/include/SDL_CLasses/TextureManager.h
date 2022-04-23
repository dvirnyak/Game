#ifndef MYCOOLGAME_TEXTUREMANAGER_H
#define MYCOOLGAME_TEXTUREMANAGER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <Game_Classes.h>

class TextureManager {
public:
    static SDL_Texture* LoadTexture(const char* fileName);
private:

};

#endif //MYCOOLGAME_TEXTUREMANAGER_H

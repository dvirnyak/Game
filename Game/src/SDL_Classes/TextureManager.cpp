#include <TextureManager.h>
#include "SDL_Interface.h"

SDL_Texture* TextureManager::LoadTexture(const char* texture) {
    SDL_Surface* tempSurface = IMG_Load(texture);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(SDL_Interface::renderer, tempSurface);
    SDL_FreeSurface(tempSurface);
    return tex;
}
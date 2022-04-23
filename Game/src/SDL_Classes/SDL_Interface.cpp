#include "SDL_Interface.h"

SDL_Renderer* SDL_Interface::renderer = NULL;

SDL_Interface::SDL_Interface() {
}

SDL_Interface::~SDL_Interface() {
    Clean();
}

bool SDL_Interface::Init(const char* title, int width, int height, bool fullscreen, int FPS) {
    bool isInitialized = false;

    int flags = 0;
    if (fullscreen) {
        flags += SDL_WINDOW_FULLSCREEN;
    }

    frameDelay_ = 1000 / FPS;
    if (SDL_Init(SDL_INIT_EVENTS) == 0) {
        std::cout << "it has been initialized\n";

        window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                  width, height, flags);
        if (window) {
            std::cout << "window created!\n";
        }

        renderer = SDL_CreateRenderer(window, -1, 0);

        if (renderer) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "renderer created!\n";
        }

        isInitialized = true;

    } else {
        std::cout << "smth went wrong:\n";
        std::cout << "Error : " << SDL_GetError() << std::endl;
        isInitialized = false;
    }
    return isInitialized;
}

Event SDL_Interface::HandleEvents() {
    frameStart_ = SDL_GetTicks();

    SDL_Event eventSDL;
    SDL_PollEvent(&eventSDL);

    Event eventInterface;
    switch (eventSDL.type) {
        case SDL_QUIT:
            eventInterface = Event("Quit");
            break;
        case SDL_MOUSEMOTION:
            eventInterface = Event("MouseMove",
                                   Coordinates(eventSDL.motion.x, eventSDL.motion.y));
            break;
        default:
            break;
    }
    return eventInterface;
}

void SDL_Interface::ClearScreen() {
    SDL_RenderClear(renderer);
}

void SDL_Interface::PresentScreen() {
    SDL_RenderPresent(renderer);

    //speed booster
    uint32_t frameTime = SDL_GetTicks() - frameStart_;
    if (frameDelay_ > frameTime) {
        SDL_Delay(frameDelay_ - frameTime);
    }
}

void SDL_Interface::Clean() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    std::cout << "it's cleaned\n";
}

void SDL_Interface::LoadImage(Image* img) {
    ImageToGameObject[img] = new GameObject(img);
}

void SDL_Interface::RenderImage(Image* img) {
    ImageToGameObject[img]->Render();
}

void SDL_Interface::DeleteImage(Image* img) {
    delete ImageToGameObject[img];
    auto it = ImageToGameObject.find(img);
    ImageToGameObject.erase(it);
};
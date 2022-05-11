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
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
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

    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(SDL_Interface::renderer, 122, 163, 248, 0.8);

    return isInitialized;
}
Coordinates lastMouseLocation(0, 0);
Event SDL_Interface::HandleEvents() {
    //frameStart_ = SDL_GetTicks();

    SDL_Event eventSDL;
    SDL_PollEvent(&eventSDL);

    Event eventInterface;

    int x, y;
    SDL_GetMouseState(&x, &y);
    Coordinates mouse(x, y);

    bool left = false, right = false;
    const Uint8 *state = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_LEFT]) {
        left = true;
    }
    if (state[SDL_SCANCODE_RIGHT]) {
        right = true;
    }

    switch (eventSDL.type) {
        case SDL_QUIT:
            eventInterface = Event("Quit");
            break;
        case SDL_MOUSEMOTION:
            mouse = Coordinates(eventSDL.motion.y, eventSDL.motion.x);
            eventInterface = Event("MouseMove",
                                           mouse, left, right);
            break;
        default:
            eventInterface = Event("default", Coordinates(0,0),
                                   left, right);
            break;
    }

    return eventInterface;
}

void SDL_Interface::ClearScreen() {
    SDL_RenderClear(renderer);
}

void SDL_Interface::PresentScreen() {
    //speed booster
    uint32_t frameTime = SDL_GetTicks() - frameStart_;
    if (frameDelay_ > frameTime) {
        if (frameDelay_ > frameTime * 1.01) {
            SDL_Delay(frameDelay_ - frameTime);
        }
    } else {
        frameStart_ = SDL_GetTicks();
        SDL_RenderPresent(renderer);
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

void SDL_Interface::PutPixel(int x, int y, int r, int g, int b, int a) {
    std::cout << Coordinates(x, y) << "\n";
    SDL_SetRenderDrawColor(SDL_Interface::renderer, r, g, b, a);
    SDL_RenderDrawPoint(SDL_Interface::renderer, x, y);
    SDL_SetRenderDrawColor(SDL_Interface::renderer, 39, 106, 245, 255);
}
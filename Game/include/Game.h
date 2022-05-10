#ifndef MYCOOLGAME_GAME_H
#define MYCOOLGAME_GAME_H

#include <SDL_Interface.h>
#include <Game_Classes.h>

class Game {
public:
    Game();
    ~Game();
    void Init(const char* Title, int width, int height, bool fullscreen, int FPS);
    void HandleEvents();
    void Update();
    void Render();
    void Clean();
    bool Running();

    inline static Interface* Interface_;
    inline static int FPS_;

private:
    inline static Ship* player_;
    inline static Map* map_;
    inline static Coordinates center_;
    bool isRunning_ = false;
};

#endif //MYCOOLGAME_GAME_H
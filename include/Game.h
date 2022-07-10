#ifndef MYCOOLGAME_GAME_H
#define MYCOOLGAME_GAME_H

#include <SDL_Interface.h>
#include <Game_Classes.h>

class Game {
public:
    Game();
    ~Game();
    void Init(const char* title, int width, int height, bool fullscreen, int fps);
    void HandleEvents();
    void Update();
    void Render();
    void Clean();
    bool Running();

    inline static Interface* interface;
    inline static double dt;

private:

    inline static Ship* player_;
    inline static Map* map_;
    inline static Coordinates center_;
    inline static Object* arrow_;

    inline static int fps_;
    bool is_running_ = false;

    void GameObjectsGeneration();
};

#endif //MYCOOLGAME_GAME_H
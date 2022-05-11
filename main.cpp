#include <Game.h>

int main(int argc, char **argv) {
    const int FPS = 60;
    Game* game = new Game();
    game->Init("Ship_Game", 800, 800, false, FPS);
    while (game->Running()) {
        game->HandleEvents();
        game->Update();
        game->Render();
    }
    game->Clean();
    delete game;
    return 0;
}

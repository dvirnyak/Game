#include <Game.h>

int main(int argc, char **argv) {
    const int FPS = 60;
    Game* game = new Game();
    game->Init("Ship_Game", 900, 640, false, FPS);
    while (game->Running()) {
        game->HandleEvents();
        game->Update();
        game->Render();
    }
    game->Clean();
    return 0;
}

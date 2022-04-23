#include "Game.h"

Game::Game() {
    Interface_ = new SDL_Interface();
}

Game::~Game() {
    Clean();
    delete Interface_;
    std::cout << "bye!\n";
}

void Game::Init(const char* title, int width, int height, bool fullscreen, int FPS) {
    center_ = Coordinates(width/2, height/2);
    FPS_ = FPS;
    if (Interface_->Init(title, width, height, fullscreen, FPS)) {
        std::cout << "it has been initialized\n";
        isRunning_ = true;
    } else {
        std::cout << "not initialized\n";
        isRunning_ = false;
    }
    player_ = new Ship(Coordinates(100, 100.001), 0, Vector2D(0, 0));
    new Ship(Coordinates(90, -50), -400, Vector2D(0,0));
    new Ship(Coordinates(50, -10), 60, Vector2D(Coordinates(50, 0)));
    new Ship(Coordinates(0, 0), 0, Vector2D(0,0));
    new Ship(Coordinates(10, 50), 0, Vector2D(0, 0));
}

void Game::HandleEvents() {
    //not ready yet
    Event event = Interface_->HandleEvents();
    if (event.type == "Quit") {
        isRunning_ = false;
    } else if (event.type == "MouseMove") {
        //std::cout << event.coordinates.x << " " << event.coordinates.y << "kk\n";
    }
}

void Game::Update() {
    for (auto & object : Object::objects) {
        object->Update();
    }
    player_->Move(Coordinates(0, 0),0.5);
    for (auto & ship : Ship::ships) {
        //ship->Move(1, 0.5);
    }
}

void Game::Render() {
    Interface_->ClearScreen();
    //without '* 1' it doesn't work...
    Image::SetViewPoint(player_->GetCoordinates() * 1, center_, player_->GetAngle());
    //Image::SetZoom(0.7);
    for (auto & object : Object::objects) {
        object->GetImage()->Draw();
    }
    Interface_->PresentScreen();
}

void Game::Clean() {
    Object::Clean();
    Interface_->Clean();
    std::cout << "it's cleaned\n";
    std::cout << Ship::ships.size() << "\n";
}

bool Game::Running() {
    return isRunning_;
}

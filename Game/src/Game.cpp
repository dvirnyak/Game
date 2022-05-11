#include "Game.h"

Game::Game() {
    Interface_ = new SDL_Interface();
}

Game::~Game() {
    Clean();
    delete Interface_;
    delete map_;
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
    map_ = new Map(Sizes(width * 10, height * 10), center_ * 10);


    new Island(Coordinates(100, 100), 234);
    new Island(Coordinates(300, 150), 32);
    new Island(Coordinates(50, 50), 984);
    new Island(Coordinates(-50, -70), 94);

    new Ship(Coordinates(10, 1), -400, Vector2D(0,0) * 0.01);
    new Ship(Coordinates(500, -10), 60, Vector2D(Coordinates(0, 0)));
    new Ship(Coordinates(0, 500), 0, Vector2D(0, 0));

    player_ = new Ship(Coordinates(0, 0.001), 360, Vector2D(0, 0));
    arrow_ = new Object("Arrow", Coordinates(width / 2, height * 0.1));
    arrow_->GetImage()->FixPosition();
}

void Game::HandleEvents() {
    Event event = Interface_->HandleEvents();
    Update();
    if (event.type == "Quit") {
        isRunning_ = false;
    }
    if (event.type == "MouseMove") {
        Vector2D direction(center_ - event.coordinates);
        player_->SetSailsDirection(direction);
    }

    if (event.KeyLeftPressed) {
        player_->ChangeAngle(-0.1);
    } else if (event.KeyRightPressed) {
        player_->ChangeAngle(0.1);
    }
    Update();
}

void Game::Update() {
    map_->Update();
    Vector2D wind = Map::GetWind(player_->GetCoordinates());
    arrow_->MoveTo(arrow_->GetCoordinates(), wind.GetAngle() - 90);
    for (auto & object : Object::objects) {
        object->Update();
    }
    player_->Update();
}

void Game::Render() {

    //without '* 1' it doesn't work...
    Image::SetViewPoint(player_->GetCoordinates() * 1, center_, player_->GetAngle());
    Image::SetZoom(0.7);

    map_->Draw();
    for (auto & object : Object::objects) {
        object->GetImage()->Draw();
    }
    Interface_->PresentScreen();
    Interface_->ClearScreen();
}

void Game::Clean() {
    Object::Clean();
    Interface_->Clean();
    std::cout << "it's cleaned\n";
}

bool Game::Running() {
    return isRunning_;
}

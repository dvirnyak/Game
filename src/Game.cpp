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
    map_ = new Map(Sizes(width * 100, height * 100), center_ * 100);

    int rand_int = rand() % 10000;
    for (int i = 0; i < 25; ++i) {
        rand_int *= 123456789;
        rand_int %= 1000000;

        bool rand_bool = rand_int % 2;
        double x, y, angle;
        x = rand_int % 1000000; x /= 123;
        y = (rand_int * 200 + 123456) % 2000000; y /= 234;
        Coordinates coordinates = Coordinates(x, y) *= (rand_bool) ? -1 : 1;
        angle = Vector2D::normaliseAngle(rand() % 7600 / 42);

        int h, w;
        h = rand_int % 200 + 400;
        w = h;
        Island* island = new Island(Coordinates(x, y), angle);
        island->Resize(Sizes(h, w));
    }

    for (int i = 0; i < 5; ++i) {
        rand_int += 123456789;
        rand_int %= 1000000;

        bool rand_bool = rand_int % 2;
        double x, y, angle;
        x = rand_int % 100000; x /= 123;
        y = (rand_int * 200 + 123456) % 200000; y /= 234;
        Coordinates coordinates = Coordinates(x, y) *= (rand_bool) ? -1 : 1;
        angle = Vector2D::normaliseAngle(rand() % 7600 / 42);
        new Ship(Coordinates(x, y), angle);
    }

    player_ = new Ship(Coordinates(100, 100), -90, Vector2D(0, 0));
    arrow_ = new Object("Arrow", Coordinates(width / 2, height * 0.1), -90);
    arrow_->GetImage()->FixPosition();
}

void Game::HandleEvents() {
    Event event = Interface_->HandleEvents();
    Update();
    if (event.type == "Quit") {
        isRunning_ = false;
    }
    if (event.type == "MouseMove") {
        Vector2D direction(event.coordinates - center_);
        player_->SetSailsDirection(direction);
    }

    if (event.KeyLeftPressed) {
        player_->ChangeAngle(-0.1);
    }
    if (event.KeyRightPressed) {
        player_->ChangeAngle(0.1);
    }
    if (event.FireLeft) {
        player_->Fire(true);
    }
    if (event.FireRight) {
        player_->Fire(false);
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
    //Object::CheckCollisions();
    Object::DeleteKilled();
}

void Game::Render() {

    //without '* 1' it doesn't work...
    Image::SetViewPoint(player_->GetCoordinates() * 1, center_, player_->GetAngle());
    Image::SetZoom(0.5);

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

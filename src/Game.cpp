#include "Game.h"

Game::Game() {
    interface = new SDL_Interface();
}

Game::~Game() {
    // delete Objects
    Clean();

    // delete non-Objects
    delete interface;
    delete map_;
    std::cout << "bye!\n";
}

void Game::Init(const char* title, int width, int height, bool fullscreen, int fps) {

    fps_ = fps;
    dt = double(1) / fps;

    if (interface->Init(title, width, height, fullscreen, fps_)) {
        std::cout << "it has been initialized\n";
        is_running_ = true;
    } else {
        std::cout << "not initialized\n";
        is_running_ = false;
    }

    center_ = Coordinates(width / 2, height / 2);
    map_ = new Map(Sizes(width, height), center_);

    GameObjectsGeneration();

    player_ = new Ship(Coordinates(100, 100), -90, Vector2D(0, 0));

    arrow_ = new Object("Arrow", Coordinates(width / 2, height * 0.1), -90);
    arrow_->GetImage()->FixPosition();
}

void Game::HandleEvents() {
    for (int i = 0; i < 10; ++i) {
        Event event = interface->HandleEvents();

        if (event.type == "Quit") {
            is_running_ = false;
        }

        if (event.type == "MouseMove") {
            Vector2D direction(event.coordinates - center_);
            player_->SetSailsDirection(direction);
        }

        if (event.KeyLeftPressed) {
            player_->ChangeAngle(-0.01);
        }
        if (event.KeyRightPressed) {
            player_->ChangeAngle(0.01);
        }
        if (event.FireLeft) {
            player_->Fire(true);
        }
        if (event.FireRight) {
            player_->Fire(false);
        }
    }
}

void Game::Update() {
    map_->Update();

    Vector2D wind = Map::GetWind(player_->GetCoordinates());
    arrow_->SetPosition(arrow_->GetCoordinates(), wind.GetAngle() - 90);

    for (auto & object : Object::objects) {
        object->Update();
    }

    Object::DeleteKilled();
}

void Game::Render() {

    //without '* 1' it doesn't work...
    Image::SetViewPoint(player_->GetCoordinates() * 1, center_, player_->GetAngle());
    Image::SetZoom(0.5);

    map_->Draw();
    for (auto & object : Object::objects) {
        object->Draw();
    }

    interface->PresentScreen();
    interface->ClearScreen();
}

void Game::Clean() {
    Object::Clean();
    interface->Clean();
    std::cout << "it's cleaned\n";
}

bool Game::Running() {
    return is_running_;
}

void Game::GameObjectsGeneration() { // TODO
    int rand_int = rand() % 10000;
    for (int i = 0; i < 200; ++i) {
        rand_int *= 123456789;
        rand_int %= 1000000;

        bool rand_bool = rand_int % 2;
        double x, y, angle;
        x = rand_int % 1000000; x /= 123;
        y = (rand_int * 200 + 123456) % 2000000; y /= 234;
        Coordinates coordinates = Coordinates(x, y) *= (rand_bool) ? -1 : 1;
        angle = Vector2D::normaliseAngle(rand() % 7600 / 42);

        int h, w;
        h = rand_int % 400 + 800;
        w = h;
        Island* island = new Island(Coordinates(x, y), angle);
        island->Resize(Sizes(w, h));
    }

    rand_int = rand() % 10000;
    for (int i = 0; i < 10; ++i) {
        rand_int += 123456789;
        rand_int %= 1000000;

        bool rand_bool = rand_int % 2;
        double x, y, angle;
        x = rand_int % 1000000; x /= 123;
        y = (rand_int * 200 + 123456) % 2000000; y /= 234;
        Coordinates coordinates = Coordinates(x, y) *= (rand_bool) ? -1 : 1;
        angle = Vector2D::normaliseAngle(rand() % 7600 / 42);
        new Ship(Coordinates(x, y), angle);
    }
}

#include <iostream>
#include "Map.h"
#include "Game.h"

Map::Map(Sizes sizes, Coordinates center) {
    sizes_ = sizes;
    center_ = center;
    img_ = new Image(center, sizes);
    map_ = deque<deque<Cell*>>(deque<deque<Cell*>>(
            sizes.width / block_size + 1, deque<Cell*>(sizes.height / block_size + 1)));

    for (int i = 0; i < sizes_.width / block_size; ++i) {
        for (int j = 0; j < sizes_.height / block_size; ++j) {
            map_[i][j] = new Cell();
        }
    }

    for (int i = 0; i < sizes_.width / block_size; ++i) {
        for (int j = 0; j < sizes_.height / block_size; ++j) {
            map_[i][j]->pressure = rand() % 500;
        }
    }

}

Map::~Map() {
    for (int i = 0; i < sizes_.width; ++i) {
        for (int j = 0; j < sizes_.height; ++j) {
            delete map_[i][j];
        }
    }
    delete img_;
}

void Map::Draw() {
}

void Map::Update() {
    if (update_count_ != 4000) {
        ++update_count_;
        return;
    }
    update_count_ = 0;
    double angle = 45, abs = 0.05;

    for (int i = 1; i < sizes_.width / block_size - 1; ++i) {
        for (int j = 1; j < sizes_.height / block_size - 1; ++j) {
            map_[i][j]->pressure = map_[i-1][j]->pressure + map_[i+1][j]->pressure +
                    map_[i][j-1]->pressure + map_[i][j+1]->pressure;
            map_[i][j]->pressure *= 0.25;
            map_[i][j]->pressure += rand() % 10;
        }
    }

    for (int i = 1; i < sizes_.width / block_size - 1; ++i) {
        for (int j = 1; j < sizes_.height / block_size - 1; ++j) {
            Vector2D wind;

            wind += Vector2D(Coordinates(1, 0) * (map_[i+1][j]->pressure - map_[i][j]->pressure));
            wind += Vector2D(Coordinates(-1, 0) * (map_[i-1][j]->pressure - map_[i][j]->pressure));
            wind += Vector2D(Coordinates(0, 1) * (map_[i][j+1]->pressure - map_[i][j]->pressure));
            wind += Vector2D(Coordinates(0, -1) * (map_[i][j-1]->pressure - map_[i][j]->pressure));

            map_[i][j]->wind = wind;
        }
    }

    //map_[i][j]->wind = Vector2D(angle, abs, true);

}

Vector2D Map::GetWind(Coordinates coordinates) {
    int i = (coordinates + center_).x / block_size;
    int j = (coordinates + center_).y / block_size;
    return map_[i][j]->wind;
}

bool Map::inMap(Coordinates coordinates) {
    coordinates += center_;
    if (coordinates.x <= 0 || coordinates.y <= 0 ||
    coordinates.x >= sizes_.width || coordinates.y >= sizes_.height) {
        std::cout << "false\n";
        return false;
    }
    return true;
}

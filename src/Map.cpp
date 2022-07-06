#include <iostream>
#include "Map.h"
#include "Game.h"

Map::Map(Sizes sizes, Coordinates center) {
    sizes_ = sizes;
    center_ = center;
    map_ = deque<deque<Cell*>>(deque<deque<Cell*>>(
            sizes.width / block_size + 1, deque<Cell*>(sizes.height / block_size + 1)));

    for (int i = 0; i < sizes_.width / block_size; ++i) {
        for (int j = 0; j < sizes_.height / block_size; ++j) {
            map_[i][j] = new Cell();
        }
    }

    for (int i = 0; i < sizes_.width / block_size; ++i) {
        for (int j = 0; j < sizes_.height / block_size; ++j) {
            map_[i][j]->pressure = (rand() + i * 1234) % 100;
        }
    }

    map_[0][0]->wind += Vector2D(100, 100);
    map_[sizes_.width / block_size - 1][0]->wind += Vector2D(-100, 100);
    map_[0][sizes_.height / block_size - 1]->wind += Vector2D(100, -100);
    map_[sizes_.width / block_size - 1][sizes_.height / block_size - 1]->wind += Vector2D(-100, -100);

    last_update = time(NULL);
}

Map::~Map() {
    for (int i = 0; i < sizes_.width / block_size + 1; ++i) {
        for (int j = 0; j < sizes_.height / block_size + 1; ++j) {
            delete map_[i][j];
        }
    }
}

void Map::Draw() {
}

void Map::Update() {
    if (time(NULL) - last_update < interval) {
        return;
    }
    last_update = time(NULL);

    for (int i = 1; i < sizes_.width / block_size - 1; ++i) {
        for (int j = 1; j < sizes_.height / block_size - 1; ++j) {
            map_[i][j]->pressure = map_[i-1][j]->pressure + map_[i+1][j]->pressure +
                    map_[i][j-1]->pressure + map_[i][j+1]->pressure;
            map_[i][j]->pressure *= 0.2;
            map_[i][j]->pressure += rand() % 50;
        }
    }


    for (int i = 1; i < sizes_.width / block_size - 1; ++i) {
        for (int j = 1; j < sizes_.height / block_size - 1; ++j) {
            Vector2D wind;

            wind += Vector2D(Coordinates(1, 0) * (map_[i+1][j]->pressure - map_[i][j]->pressure));
            wind += Vector2D(Coordinates(-1, 0) * (map_[i-1][j]->pressure - map_[i][j]->pressure));
            wind += Vector2D(Coordinates(0, 1) * (map_[i][j+1]->pressure - map_[i][j]->pressure));
            wind += Vector2D(Coordinates(0, -1) * (map_[i][j-1]->pressure - map_[i][j]->pressure));
            if (wind.GetAbs() < 1000) {
                wind += Vector2D(wind.GetAngle(), 1000, bool());
            };

            map_[i][j]->wind = wind;
        }
    }


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
        return false;
    }
    return true;
}

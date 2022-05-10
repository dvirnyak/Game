#include <iostream>
#include "Map.h"

Map::Map(Sizes sizes, Coordinates center) {
    sizes_ = sizes;
    image_ = new Image("../assets/island.bmp", center, sizes_);
    center_ = center;
    map_ = deque<deque<Cell*>>(deque<deque<Cell*>>(
            sizes.width, deque<Cell*>(sizes.height)));

    for (int i = 0; i < sizes_.width; ++i) {
        for (int j = 0; j < sizes_.height; ++j) {
            map_[i][j] = new Cell();
        }
    }

}

Map::~Map() {
    for (int i = 0; i < sizes_.width; ++i) {
        for (int j = 0; j < sizes_.height; ++j) {
            delete map_[i][j];
        }
    }
    delete image_;
}

void Map::Draw() {
    image_->Draw();
}

void Map::Update() {
    //std::cout << update_count_;
    if (update_count_ == sizes_.width - 1) {
        update_count_ = 0;
    }
    ++update_count_;
    double angle = 45, abs = 0.05;
    int i = update_count_;
    //for (int i = 0; i < sizes_.width; ++i) {
        for (int j = 0; j < sizes_.height; ++j) {
            map_[i][j]->wind = Vector2D(angle, abs, true);
            image_->SetColor(2, 2, 255, 0, 255, 128);
        }
    //}
}

Vector2D Map::GetWind(Coordinates coordinates) {
    int i = (coordinates + center_).x;
    int j = (coordinates + center_).y;
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

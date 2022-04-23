#include <Image.h>
#include <Game.h>

Image::Image(string source, Coordinates coordinates,
             Sizes sizes, double angle,
             Coordinates centerIm) : source(source),
                                       coordinates(coordinates),
                                       sizes(sizes), angle(angle) {
    Game::Interface_->LoadImage(this);
    center = centerIm;
}

Image::~Image() {
    Game::Interface_->DeleteImage(this);
}

void Image::Update(Coordinates newCoordinates, Sizes newSizes, double newAngle) {
    coordinates = newCoordinates;
    sizes = newSizes;
    angle = newAngle;
}

void Image::Draw() {
    //for not copying of the picture by creating a new Image object
    Sizes originalSizes = sizes;
    sizes *= zoom_;

    Coordinates originalCoordinates = coordinates;
    coordinates *= zoom_;
    coordinates -= viewPoint_ + Coordinates(sizes.width / 2, sizes.height / 2);

    Coordinates originalCenter = center;
    center *= zoom_;
    //std::cout << center.x << " " << center.y << "\n";

    //double originalAngle = angle;
    //angle -= viewAngle_;

    Game::Interface_->RenderImage(this);

    //angle = originalAngle;
    center = originalCenter;
    coordinates = originalCoordinates;
    sizes = originalSizes;
}

void Image::SetViewPoint(const Coordinates viewPoint, const double angle) {
    viewPoint_ = viewPoint;
    viewAngle_ = angle;
}

void Image::SetViewPoint(const Coordinates playerCoordinates, const Coordinates center,
                         const double angle) {
    viewPoint_ = playerCoordinates * zoom_ - center;
    viewAngle_ = angle;
}

void Image::Zoom(double k) {
    zoom_ *= k;
}

void Image::SetZoom(double k) {
    zoom_ = k;
}
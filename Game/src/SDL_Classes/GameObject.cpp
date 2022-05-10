#include <GameObject.h>
#include <SDL_Interface.h>

GameObject::GameObject(Image* img) : img_(img) {
    objTexture = TextureManager::LoadTexture(img->source.c_str());
}

GameObject::GameObject() {

}

GameObject::~GameObject() {
    SDL_DestroyTexture(objTexture);
}

void GameObject::Render() {
    SDL_Rect cropRect, destRect;
    destRect.h = img_->sizes.height;
    destRect.w = img_->sizes.width;
    destRect.x = img_->coordinates.x;
    destRect.y = img_->coordinates.y;

    SDL_Point center = {img_->sizes.width / 2, img_->sizes.height / 2};//{static_cast<int>(img_->center.x),
                        //static_cast<int>(img_->center.y)};
    // the center where the texture will be rotated.
    SDL_RendererFlip flip = SDL_FLIP_NONE;

    //SDL_RenderSetViewport(SDL_Interface::renderer, &viewRect);
    //cropRect = {x, y, h, w}; - in case of needed croping

    SDL_RenderCopyEx(SDL_Interface::renderer, objTexture, NULL, &destRect, img_->angle, &center, flip);
}

void GameObject::SetPixel(int x, int y, int r, int g, int b, int a) {
    std::vector< unsigned char > pixels( img_->sizes.width * img_->sizes.height * 4, 0 );

}


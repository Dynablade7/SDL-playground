#include "Sprite.h"

Sprite::Sprite(SDL_Texture* spriteSheet, SDL_Rect clip) :
     _spriteSheet(spriteSheet), _clip(clip) {
}

void Sprite::draw(SDL_Renderer* renderer, int x, int y, double angle, SDL_Point* center,
                  SDL_RendererFlip flip) {
    // The rectangle that defines the position and size the sprite will have
    // when drawn to the screen. In this function, the size will be the same
    // as the sprite is on the sprite sheet.
    SDL_Rect destination(_clip);
    destination.x = x;
    destination.y = y;
    destination.w = _clip.w;
    destination.h = _clip.h;
    // Render sprite
    SDL_RenderCopyEx(renderer, _spriteSheet, &_clip, &destination, angle, center, flip);
}

void Sprite::drawResized(SDL_Renderer* renderer, int x, int y, int w, int h,
                         double angle, SDL_Point* center, SDL_RendererFlip flip) {
    // The rectangle that defines the position and size the sprite will have
    // when drawn to the screen.
    SDL_Rect destination(_clip);
    destination.x = x;
    destination.y = y;
    destination.w = w;
    destination.h = h;
    // Render sprite
    SDL_RenderCopyEx(renderer, _spriteSheet, &_clip, &destination, angle, center, flip);
}

double Sprite::getCenterX() {
    return _clip.w / 2;
}

double Sprite::getCenterY() {
    return _clip.h / 2;
}


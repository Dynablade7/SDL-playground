#include "Sprite.h"
#include <stdio.h>
#include <iostream>

Sprite::Sprite(SDL_Texture* spriteSheet, SDL_Rect clip) {
    _spriteSheet = spriteSheet;
    _clip = clip;
}

void Sprite::draw(SDL_Renderer* renderer, int x, int y) {
    /* The rectangle that defines the position and size the sprite will have
    when drawn to the screen. In this function, the size will be the same
    as the sprite is on the sprite sheet. */
    SDL_Rect destination(_clip);
    destination.x = x;
    destination.y = y;
    destination.w = _clip.w;
    destination.h = _clip.h;
    // Render sprite
    SDL_RenderCopy(renderer, _spriteSheet, &_clip, &destination);
}

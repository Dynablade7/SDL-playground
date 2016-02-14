#include <stdio.h>
#include "SpriteSpecs.h"

Sprite* generateSprite(SpriteEnum spriteEnum, SDL_Texture* spriteSheet) {
    // A local SDL_Rect that represents the position and size of the wanted sprite.
    SDL_Rect clip;
    switch(spriteEnum) {
    case SpriteEnum::GREEN_SQUARE:
        clip.x = 32;
        clip.y = 0;
        clip.w = 32;
        clip.h = 32;
        break;
    case SpriteEnum::RED_SQUARE:
        clip.x = 0;
        clip.y = 0;
        clip.w = 32;
        clip.h = 32;
        break;
    case SpriteEnum::TEST_SHIP:
        clip.x = 64;
        clip.y = 0;
        clip.w = 32;
        clip.h = 32;
        break;
    default:
        printf("Issue generating sprite - specified Sprite is not defined!");
        return nullptr;
    }
    return new Sprite(spriteSheet, clip);

}


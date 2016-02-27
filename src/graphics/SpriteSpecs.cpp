#include <stdio.h>
#include <vector>
#include "SpriteSpecs.h"

Sprite* generateSprite(SpriteEnum spriteEnum, SDL_Texture* spriteSheet) {
    // A local SDL_Rect that represents the position and size of the wanted sprite.
    SDL_Rect clip;
    std::vector<SDL_Rect> boundingBoxes;
    switch(spriteEnum) {
    case SpriteEnum::GREEN_SQUARE:
        clip = {32, 0, 32, 32};
        break;
    case SpriteEnum::RED_SQUARE:
        clip = {0, 0, 32, 32};
        break;
    case SpriteEnum::TEST_SHIP:
        clip = {64, 0, 21, 20};
        SDL_Rect box1;
        box1 = {0, 0, 20, 20};
        boundingBoxes.push_back(box1);
        break;
    default:
        printf("Issue generating sprite - specified Sprite is not defined!");
        return nullptr;
    }
    return new Sprite(spriteSheet, clip, boundingBoxes);
}


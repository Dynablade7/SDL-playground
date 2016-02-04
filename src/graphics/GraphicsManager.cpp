#include <stdio.h>
#include <iostream>
#include "GraphicsManager.h"
#include "Sprite.h"

GraphicsManager::~GraphicsManager() {
    // Let SDL handle the memory deallocation
    SDL_DestroyWindow(_gameWindow);
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyTexture(_spriteSheet);
    // Deallocate all dynamically allocated Sprite objects
    for (auto iter = spriteMap.begin(); iter != spriteMap.end(); ++iter) {
        delete iter->second;
    }
}

void GraphicsManager::initGraphics() {
    //Create window
    _gameWindow = SDL_CreateWindow("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if(_gameWindow == nullptr)  {
        printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
    } else {
        //Create renderer for window
        _renderer = SDL_CreateRenderer(_gameWindow, -1, SDL_RENDERER_ACCELERATED);
        if (_renderer == nullptr) {
            printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
        } else {
            //Initialize renderer color
            SDL_SetRenderDrawColor(_renderer, 0x00, 0x00, 0x00, 0xFF);

            //Initialize PNG loading
            int imgFlags = IMG_INIT_PNG;
            if(!( IMG_Init(imgFlags) & imgFlags)) {
                printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
            }
        }
    }

    // Temporary sprite testing - this will be removed later
    _spriteSheet = loadTexture("c:/testsheet.png");
    _texture = loadTexture("c:/testsheet.png");
    clip.x = 0;
    clip.y = 0;
    clip.w = 32;
    clip.h = 32;
}

SDL_Texture* GraphicsManager::loadTexture(std::string path) {
    // The final texture
    SDL_Texture* newTexture = nullptr;

    // Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == nullptr) {
        printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
    } else {
        // Create texture from surface
        newTexture = SDL_CreateTextureFromSurface(_renderer, loadedSurface);
        if (newTexture == nullptr) {
            printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        }
        //Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }
    return newTexture;
}

void GraphicsManager::GameUpdated() {
    // Clear the screen
    SDL_RenderClear(_renderer);
    // Render texture to screen
    SDL_RenderCopy(_renderer, _spriteSheet, &clip, &clip);
    // TEST SPRITE LOADING AND RENDERING
    getSprite(SpriteEnum::TEST_SHIP)->draw(_renderer, 200, 32);
    // Update screen
    SDL_RenderPresent(_renderer);
}

Sprite* GraphicsManager::getSprite(SpriteEnum spriteEnum) {
    if (spriteMap.find(spriteEnum) != spriteMap.end()) {
        return spriteMap[spriteEnum];
    } else {
        Sprite* sprite = generateSprite(spriteEnum);
        spriteMap[spriteEnum] = sprite;
        return sprite;
    }
}

Sprite* GraphicsManager::generateSprite(SpriteEnum spriteEnum) {
    // A local SDL_Rect that represents the position and size of the wanted sprite.
    SDL_Rect lclip;
    // There will be a lot of cases here if this project grows. In that case I should probably
    // move these constant values to a separate file or similar.
    switch(spriteEnum) {
    case SpriteEnum::GREEN_SQUARE:
        lclip.x = 32;
        lclip.y = 0;
        lclip.w = 32;
        lclip.h = 32;
        break;
    case SpriteEnum::RED_SQUARE:
        lclip.x = 0;
        lclip.y = 0;
        lclip.w = 32;
        lclip.h = 32;
        break;
    case SpriteEnum::TEST_SHIP:
        lclip.x = 64;
        lclip.y = 0;
        lclip.w = 32;
        lclip.h = 32;
        break;
    default:
        printf("Issue generating sprite - specified Sprite is not defined!");
        return nullptr;
    }
    return new Sprite(_spriteSheet, lclip);
}

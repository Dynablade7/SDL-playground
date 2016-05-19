#include "GraphicsManager.h"

#include <stdio.h>
#include "MapObject.h"
#include "SDL_image.h"
#include "Sprite.h"

GraphicsManager::GraphicsManager(std::vector<MapObject*>* mapObjects) :
    _mapObjects(mapObjects) {
}

GraphicsManager::~GraphicsManager() {
    // Let SDL handle the memory deallocation
    SDL_DestroyWindow(_gameWindow);
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyTexture(_spriteSheet);
    // Deallocate all dynamically allocated Sprite objects
    for (auto iter = spriteMap.begin(); iter != spriteMap.end(); ++iter) {
        delete iter->second;
        iter->second = nullptr;
    }
}

void GraphicsManager::initGraphics() {
    // Create window
    _gameWindow = SDL_CreateWindow("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                   SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if(_gameWindow == nullptr)  {
        printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
    } else {
        // Create renderer for window
        _renderer = SDL_CreateRenderer(_gameWindow, -1, SDL_RENDERER_PRESENTVSYNC);
        if (_renderer == nullptr) {
            printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
        } else {
            // Initialize renderer color
            SDL_SetRenderDrawColor(_renderer, 0x00, 0x00, 0x00, 0xFF);
            // Initialize PNG loading
            int imgFlags = IMG_INIT_PNG;
            if(!(IMG_Init(imgFlags) & imgFlags)) {
                printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
            }
        }
    }

    // At this point there is only one sprite sheet. If more are
    // added in the future, this should be done in a more elegant manner.
    _spriteSheet = loadTexture("res/spritesheets/testsheet.png");
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
        // Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }
    return newTexture;
}

void GraphicsManager::GameUpdated() {
    // Clear the screen
    SDL_RenderClear(_renderer);

    // Draw all MapObjects
    // CURRENTLY UNOPTIMIZED - of course, it should only draw those within the
    // borders of the screen. I will fix that once things start moving.
    MapObject* temp;
    for (unsigned int i = 0; i < _mapObjects->size(); ++i) {
        temp = _mapObjects->at(i);
        // Draw the MapObject
        temp->draw(_renderer, temp->getX(), temp->getY());
        // Draw the MapObject's hitboxes (debugging)
        temp->drawHitboxes(_renderer, getSprite(SpriteEnum::HITBOX));
    }
    temp = nullptr;
    SDL_RenderPresent(_renderer);
}

Sprite* GraphicsManager::getSprite(SpriteEnum spriteEnum) {
    if (spriteMap.find(spriteEnum) != spriteMap.end()) {
        return spriteMap[spriteEnum];
    } else {
        Sprite* sprite = sspecs_generateSprite(spriteEnum, _spriteSheet);
        spriteMap[spriteEnum] = sprite;
        return sprite;
    }
}

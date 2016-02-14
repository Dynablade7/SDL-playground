#include "MainGame.h"
#include <iostream>
#include <stdio.h>
#include "PlayerShip.h"
#include "SDL_image.h"

MainGame::MainGame() {
    _gameState = GameState::PLAY;
    _mapObjects = new std::vector<MapObject*>();
    _graphicsManager = new GraphicsManager(_mapObjects);
}

MainGame::~MainGame() {
    SDL_Quit();
    // Deallocate all MapObjects
    for (int i = 0; i < _mapObjects->size(); ++i) {
        delete _mapObjects->at(i);
        _mapObjects->at(i) = nullptr;
    }
    delete _graphicsManager;
    _graphicsManager = nullptr;
    delete _mapObjects;
    _mapObjects = nullptr;
}

void MainGame::run() {
    initSystems();
    gameLoop();
}

void MainGame::initSystems() {
    // Initialize SDL (might not need everything, but I'll go for that for now)
    SDL_Init(SDL_INIT_EVERYTHING);
    // Initialize graphics: create window, etc
    _graphicsManager->initGraphics();
    // Add listeners to vector for them to notified when the game is updated.
    gameUpdatedListeners.push_back(_graphicsManager);
}

void MainGame::gameLoop() {
    while (_gameState != GameState::EXIT) {
        processInput();
        notifyGameUpdatedListeners();
    }
}

void MainGame::processInput() {
    SDL_Event event;
    while(SDL_PollEvent(&event)) {
        switch(event.type) {
            case SDL_QUIT:
                _gameState = GameState::EXIT;
                break;
            case SDL_MOUSEMOTION:
                // Print the position of the mouse any time it is moved.
                std::cout << event.motion.x << " " << event.motion.y << std::endl;
                break;
            case SDL_MOUSEBUTTONDOWN:
                // Create a PlayerShip when clicking in the window.
                PlayerShip* testShip = new PlayerShip(200, 200, _graphicsManager->getSprite(SpriteEnum::TEST_SHIP));
                _mapObjects->push_back(testShip);

        }
    }
}

void MainGame::notifyGameUpdatedListeners() {
    for (GameUpdatedListener* listener : gameUpdatedListeners) {
        listener->GameUpdated();
    }
}

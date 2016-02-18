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
    // Create the player ship
    _playerShip = new PlayerShip(_graphicsManager->getSprite(SpriteEnum::TEST_SHIP));
    _mapObjects->push_back(_playerShip);
}

void MainGame::gameLoop() {
    while (_gameState != GameState::EXIT) {
        processInput();
        notifyGameUpdatedListeners();
        _playerShip->move();
    }
}

void MainGame::processInput() {
    SDL_Event event;
    while(SDL_PollEvent(&event) != 0) {
        // If user requests to quit the game
        if (event.type == SDL_QUIT) {
            _gameState = GameState::EXIT;
            break;
        }
    }
    // Process user input
    if (_playerShip != nullptr) {
        _playerShip->processInput(event);
    }
}

void MainGame::notifyGameUpdatedListeners() {
    for (GameUpdatedListener* listener : gameUpdatedListeners) {
        listener->GameUpdated();
    }
}

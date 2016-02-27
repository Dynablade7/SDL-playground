#include "MainGame.h"
#include <iostream>
#include <stdio.h>
#include "PlayerShip.h"
#include "sdl_extensions/SDL_collide.h"
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
    //_playerShip = new PlayerShip(_graphicsManager->getSprite(SpriteEnum::TEST_SHIP));
    _playerShip = new PlayerShip(32, 32, _graphicsManager);
    _mapObjects->push_back(_playerShip);
}

void MainGame::gameLoop() {
    // Timer used to calculate fps
    Timer fpsTimer;
    // Integer for keeping track of how many frames have been rendered so far
    int countedFrames = 0;
    fpsTimer.start();
    // ------- VERIFYING COLLISION FUNCTION ------
    SDL_Rect rect1 = {0, 0, 2, 5};
    SDL_Rect rect2 = {0, 0, 32, 32};
    std::cout << SDL_CollideBoundingBoxAngled(rect1, 180, rect2, 180) << std::endl;
    std::cout << SDL_CollideBoundingBox(rect1, rect2) << std::endl;
    // -------------------------------------------
    while (_gameState != GameState::EXIT) {
        // Calculate and print current avarage fps
        // int avgFPS = countedFrames / (fpsTimer.getTicks() / 1000.f);
        // std::cout << avgFPS << std::endl;
        processInput();
        notifyGameUpdatedListeners();
        _playerShip->move();
        ++countedFrames;
    }
}

void MainGame::processInput() {
    SDL_Event event;
    while(SDL_PollEvent(&event) != 0) {
        // If user requests to quit the game
        if (event.type == SDL_QUIT) {
            _gameState = GameState::EXIT;
            return;
        }
    }
    // Process user input
    if (_playerShip != nullptr) {
        _playerShip->processInput();
    }
}

void MainGame::notifyGameUpdatedListeners() {
    for (GameUpdatedListener* listener : gameUpdatedListeners) {
        listener->GameUpdated();
    }
}

#include "MainGame.h"
#include <iostream>
#include <stdio.h>
#include "PlayerShip.h"
#include "SDL_image.h"

MainGame::MainGame() {
    _gameState = GameState::PLAY;
    _mapObjects = new std::vector<MapObject*>();
    _graphicsManager = new GraphicsManager(_mapObjects);
    _collisionManager = new CollisionManager(_mapObjects);
}

MainGame::~MainGame() {
    SDL_Quit();
    // Deallocate all MapObjects
    for (unsigned int i = 0; i < _mapObjects->size(); ++i) {
        delete _mapObjects->at(i);
        _mapObjects->at(i) = nullptr;
    }
    delete _graphicsManager;
    _graphicsManager = nullptr;
    delete _mapObjects;
    _mapObjects = nullptr;
    delete _collisionManager;
    _collisionManager = nullptr;
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
    gameUpdatedListeners.push_back(_collisionManager);
    // Create the player ship
    _playerShip = new PlayerShip(0, 0, _graphicsManager);
    _mapObjects->push_back(_playerShip);
    PlayerShip* testShip1 = new PlayerShip(100, 100, _graphicsManager);
    _mapObjects->push_back(testShip1);
}

void MainGame::gameLoop() {
    // Timer used to calculate fps
    Timer fpsTimer;
    // Integer for keeping track of how many frames have been rendered so far
    int countedFrames = 0;
    fpsTimer.start();
    while (_gameState != GameState::EXIT) {
        // Calculate and print current avarage fps
        // int avgFPS = countedFrames / (fpsTimer.getTicks() / 1000.f);
        // std::cout << avgFPS << std::endl;
        processInput();
        notifyGameUpdatedListeners();
        _playerShip->moveObject();
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

#ifndef MAINGAME_H
#define MAINGAME_H

#include <iostream>
#include <vector>
#include "SDL.h"

// Forward declarations
class CollisionManager;
class GameUpdatedListener;
class GraphicsManager;
class MapObject;
class PlayerShip;
class Sprite;
class Timer;

// The possible states of the game. Might use a separate state machine later.
enum class GameState {PLAY, EXIT};

/**
 * The main game class. This class contains the game loop.
 * Start the game by calling the run() method.
 */
class MainGame {
    public:
        MainGame();
        ~MainGame();

        /**
         * Start the game by calling this method.
         */
        void run();

    private:

        /**
         * Initialize everything that need to be initialized before the game can start,
         * such as SDL and graphics.
         */
        void initSystems();

        /**
         * The main game loop.
         */
        void gameLoop();

        /**
         * While the event queue is non-empty, process the events.
         */
        void processInput();

        /**
         * The Observer pattern is used to notify certain game elements of when the game ticks.
         * All classes who use this feature must implement the interface GameUpdatedListener.
         */
        void notifyGameUpdatedListeners();

        /**
         * The current state of the game (see enum class above).
         */
        GameState _gameState;
        GraphicsManager* _graphicsManager = nullptr;
        CollisionManager* _collisionManager = nullptr;

        /**
         * A vector of all objects implementing the GameUpdatedListener interface.
         */
        std::vector<GameUpdatedListener*> gameUpdatedListeners;

        /**
         * A vector of all MapObjects in the game.
         */
        std::vector<MapObject*>* _mapObjects = nullptr;

        /**
         * The user-controlled MapObject.
         */
        PlayerShip* _playerShip = nullptr;
};

#endif // MAINGAME_H

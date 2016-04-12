#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include <vector>
#include "GameUpdatedListener.h"
#include "MapObject.h"

class CollisionManager : public GameUpdatedListener {
    public:

        /**
         * Constructor.
         * @param mapObjects - A pointer to a vector containing all the game's
         * MapObjects. These are used for collision detection.
         */
        CollisionManager(std::vector<MapObject*>* mapObjects);

        /**
         * Method derived from GameUpdatedListener.
         * This method is called whenever the game is updated and the game should
         * be checked for collisions. Utilizing the Observer design pattern.
         */
        void GameUpdated();

    private:

        /**
         * Checks for collisions between all hitboxes of all MapObject
         * currently in the game.
         * Runs in O(n^2) time, where n is the total number of hitboxes across
         * all MapObjects.
         * I will probably implement a quad-tree algorithm later to optimize
         * collision management.
         */
        void checkCollisions();
        std::vector<MapObject*>* _mapObjects = nullptr;
};

#endif // COLLISIONMANAGER_H

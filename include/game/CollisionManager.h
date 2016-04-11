#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include <vector>
#include "GameUpdatedListener.h"
#include "MapObject.h"

class CollisionManager : public GameUpdatedListener {
    public:

        /**
         * Constructor.
         * @param mapObjects - A pointer to a vetor containing all the game's
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
        void checkCollisions();
        std::vector<MapObject*>* _mapObjects = nullptr;
};

#endif // COLLISIONMANAGER_H

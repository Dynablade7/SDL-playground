#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include <vector>
#include "GameUpdatedListener.h"

// Forward declarations
class MapObject;

/**
 * An instance of this object is used to check for collisions between
 * the hitboxes of the game's MapObjects.
 *
 * This is done by iterating over all hitboxes of all MapObjects in the game
 * and checking whether they are intersecting. If the ammount of hitboxes in the
 * game turns out to be high, a quad-tree algorithm will be implemented to
 * optimize this step. Each hitbox knows how it should react to collisions with
 * other types of hitboxes - see the Hitbox base class and its subclasses for
 * detailed documentation.
 */
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
         * all MapObjects. I will probably implement a quad-tree algorithm later to optimize
         * collision management.
         */
        void checkCollisions();

        std::vector<MapObject*>* _mapObjects = nullptr;
};

#endif // COLLISIONMANAGER_H

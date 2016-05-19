#ifndef WALL_H
#define WALL_H

#include "MapObject.h"

// Forward declarations
class GraphicsManager;

/**
 * A MapObject representing a wall in the game.
 * Moving MapObjects will simply bounce off the wall when colliding with it.
 */
class Wall : public MapObject {
    public:

        /**
         * Constructor. Creates a wall object on the specified position.
         * @param x - The x position where the object will be created
         * @param y - The y position where the object will be created
         * @param sprite - A pointer to a sprite to be used by the object
         */
        Wall(int x, int y, Sprite* sprite);

        /**
         * Constructor. Creates a wall object on the specified position.
         * @param x - The x position where the object will be created
         * @param y - The y position where the object will be created
         * @param graphicsManager - the game's GraphicsManager object.
         * This is used in the constructor to get the pre-defined sprite
         * for the wall object.
         */
        Wall(int x, int y, GraphicsManager* graphicsManager);

        /**
         * Destructor.
         */
        ~Wall();

    private:

        /**
         * Implementation of pure virtual method from the base class.
         * Generates the hitboxes that are associated with the MapObject.
         */
        void generateHitboxes();
};

#endif // WALL_H

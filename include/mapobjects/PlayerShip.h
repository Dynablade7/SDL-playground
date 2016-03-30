#ifndef PLAYERSHIP_H
#define PLAYERSHIP_H

#include "MapObject.h"
#include "GraphicsManager.h"

/**
 * The class containing the MapObject controlled by the player.
 */
class PlayerShip : public MapObject {
    public:

        /**
         * Constructor. Creates a PlayerShip object on the default position.
         * See private variables START_POS_X and START_POS_Y
         * @param sprite - A pointer to the sprite of the PlayerShip
         */
        PlayerShip(Sprite* sprite);

        /**
         * Constructor. Creates a PlayerShip object on the specified position.
         * @param x - The x position where the object will be created
         * @param y - The y position where the object will be created
         * @param sprite - A pointer to the sprite of the PlayerShip
         */
        PlayerShip(int x, int y, Sprite* sprite);

        /**
         * Constructor. Creates a PlayerShip object on the specified position.
         * @param x - The x position where the object will be created
         * @param y - The y position where the object will be created
         * @param graphicsManager - A pointer to the game's GraphicsManager object.
         * In the constructor it is used to get the default sprite for this object.
         * Creating a MapObject with this approach assumes that each class knows
         * on beforehand which sprite it should be using.
         */
         PlayerShip(int x, int y, GraphicsManager* graphicsManager);

        /**
         * This method processes keyboard input using SDL_SCANCODE and acts accordingly.
         * For instance, it accelerates the PlayerShip if the W key is pressed.
         */
        void processInput();

    private:

        /**
         * Implementation of pure virtual method from the base class.
         * Generates the hitboxes that are associated with the PlayerShip.
         */
        void generateHitboxes();

        /**
         * Constants declaring the default position of the PlayerShip.
         * If no position is specified in the constructor, these will be used.
         * NOTE: Are these not initialized when the constructor is called?
         * The ship spawns at (0,0) regardless of their value right now
         */
        const int START_POS_X = 320, START_POS_Y = 32;

        /**
         * A constant that determines the speed of the PlayerShip.
         */
        const double SPEED_CONST = 0.1;

        /**
         * A constant that determines how fast the PlayerShip will turn.
         * In practice it is the number of degrees the ship will turn per tick.
         */
        const int TURN_CONST = 5;
};

#endif // PLAYERSHIP_H

#ifndef PLAYERSHIP_H
#define PLAYERSHIP_H

#include <MapObject.h>
#include "SDL.h"

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
        ~PlayerShip();

        /**
         * This function processes keyboard input and acts accordingly.
         * For instance, it sets _xVelocity and _yVelocity values if arrow keys
         * are pressed.
         * @param e - A reference to the SDL_Event that occured. Unrelevant events,
         * such as mouse clicks or unimplemented key presses, are ignored.
         */
        void processInput();

        /**
         * Changes the PlayerShip's position based on its current _xVel and _yVel values.
         */
        void move();

        /**
         * Accelerates the PlayerShip in the specified direction.
         * @param force - The force that is applied to the PlayerShip
         * @param direction - The direction (degrees) that the PlayerShip is pushed towards.
         *        0 degrees -> vertical acceleration upwards
                  90 degrees -> horizontal acceleration to the left, etc
         */
        void applyForce(double force, double direction);


    private:

        /**
         * The horizontal and vertical velocity of the PlayerShip, respectively.
         */
        double _xVel, _yVel;

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

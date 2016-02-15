#ifndef PLAYERSHIP_H
#define PLAYERSHIP_H

#include <MapObject.h>
#include <SDL.h>

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
        void processInput(SDL_Event& e);
    private:
        double _xVelocity = 0, _yVelocity = 0;
        double _direction = 0;
        const int START_POS_X = 32, START_POS_Y = 32;
};

#endif // PLAYERSHIP_H

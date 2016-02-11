#ifndef PLAYERSHIP_H
#define PLAYERSHIP_H

#include <MapObject.h>

/**
 * The class containing the MapObject controlled by the player.
 */
class PlayerShip : public MapObject {
    public:
        PlayerShip(int x, int y, Sprite* sprite);
        ~PlayerShip();
    private:
        double xVelocity = 0, yVelocity = 0;
        double direction = 0;
};

#endif // PLAYERSHIP_H

#ifndef PLAYERSHIP_H
#define PLAYERSHIP_H

#include <MapObject.h>


class PlayerShip : public MapObject {
    public:
        PlayerShip(int x, int y, Sprite* sprite);
        ~PlayerShip();
    protected:
    private:
        double xVelocity = 0, yVelocity = 0;
        double direction = 0;
};

#endif // PLAYERSHIP_H

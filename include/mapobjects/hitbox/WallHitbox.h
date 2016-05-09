#ifndef WALLHITBOX_H
#define WALLHITBOX_H

#include "Hitbox.h"

/**
 * A hitbox to be used for stationary MapObjects that do not interact
 * directly with the rest of the game.
 * When there is a collision between a WallHitbox and a Hurtbox, the owner
 * of the Hurtbox will simply bounce off the wall.
 */
class WallHitbox : public Hitbox {
    public:

        /**
         * Constructor.
         * @param x - The absolute x position of the hitbox' "upper left corner"
         * @param y - The absolute y position of the hitbox' "upper left corner"
         * @param xRel - The x position of the Hitbox' "upper left corner", relative
         * to the MapObject that created it.
         * @param yRel - The y position of the Hitbox' "upper left corner", relative
         * to the MapObject that created it.
         * @param radius - The hitbox' radius.
         */
        WallHitbox(double x, double y, double xRel, double yRel, int radius);

        /**
         * Destructor.
         */
        ~WallHitbox();
};

#endif // WALLHITBOX_H

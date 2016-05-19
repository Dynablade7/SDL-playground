#ifndef WALLHITBOX_H
#define WALLHITBOX_H

#include "Hitbox.h"

// Forward declarations
class Hurtbox;
class AttackHitbox;

/**
 * A class derived from the Hitbox class.
 * This hitbox is to be used for stationary MapObjects (e.g. walls).
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

    private:

        /**
         * Implementation of pure virtual method. See base class for general documentation.
         * Currently returns without changing anything.
         */
        CollisionAttributes resolveHurtboxCollision(Hurtbox* hb,
                                                    MapObject* obj1, MapObject* obj2);

        /**
         * Implementation of pure virtual method. See base class for general documentation.
         * Currently returns without changing anything.
         */
        CollisionAttributes resolveAttackCollision(AttackHitbox* hb,
                                                   MapObject* obj1, MapObject* obj2);

        /**
         * Implementation of pure virtual method. See base class for general documentation.
         * Currently returns without chaning anything.
         */
        CollisionAttributes resolveWallCollision(WallHitbox* hb,
                                                 MapObject* obj1, MapObject* obj2);
};

#endif // WALLHITBOX_H

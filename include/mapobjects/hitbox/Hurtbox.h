#ifndef HURTBOX_H
#define HURTBOX_H

#include "Hitbox.h"
#include "MapObject.h"

/**
 * A class derived from the Hitbox class.
 * Hurtboxes are the parts of MapObjects that interact with the environment.
 * They are used for checking for collisions with walls and other MapObjects'
 * hurtboxes and bounce off them accordingly. When they collide with an
 * AttackHitbox, the MapObject they are attatched to takes damage and is launched.
 */
class Hurtbox : public Hitbox {
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
        Hurtbox(double x, double y, double xRel, double yRel, int radius);

        virtual ~Hurtbox();

    private:

        /**
         * Implementation of pure virtual method. See base class for general documentation.
         * When two Hurtboxes collide, they simply bounce off each other.
         */
        CollisionAttributes resolveHurtboxCollision(Hurtbox* hb,
                                                    MapObject* obj1, MapObject* obj2);

        /**
         * Implementation of pure virtual method. See base class for general documentation.
         * When a Hurtbox collides with an AttackHitbox, the owner of the Hurtbox takes damage
         * and is launched.
         */
        CollisionAttributes resolveAttackCollision(AttackHitbox* hb,
                                                   MapObject* obj1, MapObject* obj2);
        /**
         * Implementation of pure virtual method. See base class for general documentation.
         * When a Hurtbox collides with a WallHitbox, the owner of the Hurtbox bounces off
         * the wall.
         */
        CollisionAttributes resolveWallCollision(WallHitbox* hb,
                                                 MapObject* obj1, MapObject* obj2);
};

#endif // HURTBOX_H

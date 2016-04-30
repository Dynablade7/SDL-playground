#ifndef HURTBOX_H
#define HURTBOX_H

#include "Hitbox.h"

/**
 * A specific type of Hitbox that is used as "body" of a MapObject.
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
};

#endif // HURTBOX_H

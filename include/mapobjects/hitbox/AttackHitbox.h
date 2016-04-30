#ifndef ATTACKHITBOX_H
#define ATTACKHITBOX_H

#include "Hitbox.h"

/**
 * A specific type of Hitbox that is used for offensive purposes.
 * When an AttackHitbox collides with a Hurtbox, the owner of the Hurtbox
 * will take damage and be launched depending on the specs of the AttackHitbox.
 */
class AttackHitbox : public Hitbox {
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
         * @param damage - The damage dealt when the hitbox collides with a Hurtbox.
         * @param launch - The power by which a MapObject will be launched when its
         * Hurtbox collides with this hitbox.
         * @param launchAngle - The angle at which a MapObject will be launched when
         * its Hurtbox collides with this hitbox.
         */
        AttackHitbox(double x, double y, double xRel, double yRel, int radius,
                     double damage, double launch, double launchAngle);
        virtual ~AttackHitbox();
        double getDamage();
        double getLaunch();
        double getLaunchAngle();

    private:

        /**
         * The damage dealt to a MapObject when an AttackHitbox collides
         * with one of its Hurtboxes.
         */
        double _damage;

        /**
         * The power by which a MapObject will be launched when an AttackHitbox
         * collides with one of its Hurtboxes.
         */
        double _launch;

        /**
         * The angle at which a MapObject will be launched when an AttackHitbox
         * collides with one of its Hurtboxes.
         *
         * The launch angle is depending on the relative angle between the colliding
         * hitboxes. If _launchAngle is 0, the MapObject being launched will be sent
         * in the same angle that is between the two hitboxes, relative to the owner
         * of the AttackHitbox. If _launchAngle is 90, it will be sent perpendicular
         * to that angle, etc.
         */
        double _launchAngle;
};

#endif // ATTACKHITBOX_H

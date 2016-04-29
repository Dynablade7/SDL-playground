#ifndef ATTACKHITBOX_H
#define ATTACKHITBOX_H

#include "Hitbox.h"

class AttackHitbox : public Hitbox {
    public:
        AttackHitbox(double x, double y, double xRel, double yRel, int radius,
                     double damage, double launch, double launchAngle);
        virtual ~AttackHitbox();
        double getDamage();
        double getLaunch();
        double getLaunchAngle();
    protected:
    private:
        double _damage;
        double _launch;
        double _launchAngle;
};

#endif // ATTACKHITBOX_H

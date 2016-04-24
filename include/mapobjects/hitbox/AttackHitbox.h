#ifndef ATTACKHITBOX_H
#define ATTACKHITBOX_H

#include "Hitbox.h"

class AttackHitbox : public Hitbox {
    public:
        AttackHitbox(double x, double y, int radius);
        virtual ~AttackHitbox();
    protected:
    private:
        double _power;
        double _launch;
};

#endif // ATTACKHITBOX_H

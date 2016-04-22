#ifndef HURTBOX_H
#define HURTBOX_H

#include <Hitbox.h>


class Hurtbox : public Hitbox {
    public:
        Hurtbox(double x, double y, int radius);
        virtual ~Hurtbox();
    protected:
    private:
};

#endif // HURTBOX_H

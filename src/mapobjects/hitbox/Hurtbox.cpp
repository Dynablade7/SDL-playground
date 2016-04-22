#include "Hurtbox.h"

Hurtbox::Hurtbox(double x, double y, int radius) :
    Hitbox(x, y, radius, HitboxType::HURTBOX) {
}

Hurtbox::~Hurtbox() {
}

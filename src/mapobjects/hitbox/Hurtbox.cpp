#include "Hurtbox.h"

Hurtbox::Hurtbox(double x, double y, double xRel, double yRel, int radius) :
    Hitbox(x, y, xRel, yRel, radius, HitboxType::HURTBOX) {
}

Hurtbox::~Hurtbox() {
}

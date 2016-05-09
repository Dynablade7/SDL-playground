#include "WallHitbox.h"

WallHitbox::WallHitbox(double x, double y, double xRel, double yRel, int radius) :
    Hitbox(x, y, xRel, yRel, radius, HitboxType::WALL) {
}

WallHitbox::~WallHitbox() {
}

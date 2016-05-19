#include "WallHitbox.h"

#include "CollisionAttributes.h"

WallHitbox::WallHitbox(double x, double y, double xRel, double yRel, int radius) :
    Hitbox(x, y, xRel, yRel, radius, HitboxType::WALL) {
}

WallHitbox::~WallHitbox() {
}

CollisionAttributes WallHitbox::resolveHurtboxCollision(Hurtbox* hb,
                                                        MapObject* obj1, MapObject* obj2) {
    CollisionAttributes c(obj1);
    return c;
}

CollisionAttributes WallHitbox::resolveAttackCollision(AttackHitbox* hb,
                                                       MapObject* obj1, MapObject* obj2) {
    CollisionAttributes c(obj1);
    return c;
}

CollisionAttributes WallHitbox::resolveWallCollision(WallHitbox* hb,
                                                     MapObject* obj1, MapObject* obj2) {
    CollisionAttributes c(obj1);
    return c;
}

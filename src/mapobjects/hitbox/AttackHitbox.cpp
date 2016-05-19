#include "AttackHitbox.h"

#include "CollisionAttributes.h"

AttackHitbox::AttackHitbox(double x, double y, double xRel, double yRel,
                           int radius, double damage, double launch, double launchAngle) :
    Hitbox(x, y, xRel, yRel, radius, HitboxType::ATTACK),
    _damage(damage), _launch(launch), _launchAngle(launchAngle) {
}

AttackHitbox::~AttackHitbox(){
}

CollisionAttributes AttackHitbox::resolveHurtboxCollision(Hurtbox* hb,
                                                          MapObject* obj1, MapObject* obj2) {
    CollisionAttributes c(obj1);
    return c;
}

CollisionAttributes AttackHitbox::resolveAttackCollision(AttackHitbox* hb,
                                                         MapObject* obj1, MapObject* obj2) {
    CollisionAttributes c(obj1);
    return c;
}

CollisionAttributes AttackHitbox::resolveWallCollision(WallHitbox* hb,
                                                       MapObject* obj1, MapObject* obj2) {
    CollisionAttributes c(obj1);
    return c;
}


double AttackHitbox::getDamage() {
    return _damage;
}

double AttackHitbox::getLaunch() {
    return _launch;
}

double AttackHitbox::getLaunchAngle() {
    return _launchAngle;
}

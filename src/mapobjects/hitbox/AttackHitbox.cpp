#include "AttackHitbox.h"

AttackHitbox::AttackHitbox(double x, double y, double xRel, double yRel,
                           int radius, double damage, double launch, double launchAngle) :
    Hitbox(x, y, xRel, yRel, radius, HitboxType::ATTACK), _damage(damage), _launch(launch), _launchAngle(launchAngle) {
}

AttackHitbox::~AttackHitbox(){
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

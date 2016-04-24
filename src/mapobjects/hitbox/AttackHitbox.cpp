#include "AttackHitbox.h"

AttackHitbox::AttackHitbox(double x, double y, int radius) :
    Hitbox(x, y, radius, HitboxType::ATTACK) {
}

AttackHitbox::~AttackHitbox(){
}

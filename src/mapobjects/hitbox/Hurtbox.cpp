#include "Hurtbox.h"

#include "AttackHitbox.h"
#include "CollisionAttributes.h"
#include "Vector2D.h"

Hurtbox::Hurtbox(double x, double y, double xRel, double yRel, int radius) :
    Hitbox(x, y, xRel, yRel, radius, HitboxType::HURTBOX) {
}

Hurtbox::~Hurtbox() {
}

CollisionAttributes Hurtbox::resolveHurtboxCollision(Hurtbox* hb,
                                                     MapObject* obj1, MapObject* obj2) {
    CollisionAttributes c(obj1);
    // Very simple bouncing simulation, utilizing the property of total elastic collision
    // The resulting angles are not entirely correct at this point
    double mass1 = 1, mass2 = 1; // Mass should be determined in each MapObject later
    Vector2D vel1(obj1->getXVel(), obj1->getYVel());
    Vector2D vel2(obj2->getXVel(), obj2->getYVel());
    // Calculate the new velocities
    Vector2D newVel = (vel1 * (mass1 - mass2) + vel2 * 2 * mass2) / (mass1 + mass2);
    Vector2D* finalVel = new Vector2D(newVel.getX(), newVel.getY());
    c.setVelocity(finalVel);
    return c;
}

CollisionAttributes Hurtbox::resolveAttackCollision(AttackHitbox* hb,
                                                    MapObject* obj1, MapObject* obj2) {
    CollisionAttributes c(obj1);
    double launchAngle = hitbox_rel_angle(this, hb) + hb->getLaunchAngle() - 90;
    c.setForce(hb->getLaunch(), launchAngle);
    return c;
}

CollisionAttributes Hurtbox::resolveWallCollision(WallHitbox* hb,
                                                  MapObject* obj1, MapObject* obj2) {
    CollisionAttributes c(obj1);
    // A very simple and not really realistic bouncing method: reverse the velocities
    Vector2D* finalVel = new Vector2D(obj1->getXVel() * -1, obj1->getYVel() * -1);
    c.setVelocity(finalVel);
    return c;
}

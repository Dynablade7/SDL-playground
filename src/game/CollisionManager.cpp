#include "CollisionManager.h"

#include <iostream>
#include "Vector2D.h"

CollisionManager::CollisionManager(std::vector<MapObject*>* mapObjects) :
    _mapObjects(mapObjects) {
}

void CollisionManager::checkCollisions() {
    for (unsigned int i = 0; i < _mapObjects->size() - 1; ++i) {
        MapObject* temp1 = _mapObjects->at(i);
        MapObject* temp2 = _mapObjects->at(i + 1);
        for (unsigned int j = 0; j < temp1->getHitboxes().size(); ++j) {
            for (unsigned int k = 0; k < temp2->getHitboxes().size(); ++k) {
                Hitbox* hb1 = temp1->getHitboxes().at(j);
                Hitbox* hb2 = temp2->getHitboxes().at(k);
                if (hitbox_collision(hb1, hb2)) {
                    resolveCollision(temp1, hb1, temp2, hb2);
                }
            }
        }
    }
}

void CollisionManager::resolveCollision(MapObject* obj1, Hitbox* hb1, MapObject* obj2, Hitbox* hb2) {
    // Perform actions depending on which types of hitboxes collide
    if (hb1->getHitboxType() == HitboxType::HURTBOX &&
        hb2->getHitboxType() == HitboxType::HURTBOX) {
        // Both are Hurtboxes
        Hurtbox* box1 = static_cast<Hurtbox*>(hb1);
        Hurtbox* box2 = static_cast<Hurtbox*>(hb2);
        resolveDoubleHurtbox(obj1, box1, obj2, box2);

    } else if (hb1->getHitboxType() == HitboxType::HURTBOX &&
               hb1->getHitboxType() == HitboxType::ATTACK) {
        // One is AttackHitbox, the other is Hurtbox
        AttackHitbox* box1 = static_cast<AttackHitbox*>(hb2);
        Hurtbox* box2 = static_cast<Hurtbox*>(hb1);
        resolveAttackHurtbox(obj1, box1, obj2, box2);

    } else if (hb1->getHitboxType() == HitboxType::ATTACK &&
               hb2->getHitboxType() == HitboxType::HURTBOX) {
        // One is Hurtbox, the other is AttackHitbox
        AttackHitbox* box1 = static_cast<AttackHitbox*>(hb1);
        Hurtbox* box2 = static_cast<Hurtbox*>(hb2);
        resolveAttackHurtbox(obj1, box1, obj2, box2);

    } else if (hb1->getHitboxType() == HitboxType::ATTACK &&
               hb2->getHitboxType() == HitboxType::ATTACK){
    } else {
        std::cout << "Hitbox not specified in CollisionManager::resolveCollision" << std::endl;
    }
}

void CollisionManager::resolveDoubleHurtbox(MapObject* obj1, Hurtbox* hb1,
                                            MapObject* obj2, Hurtbox* hb2) {

    double mass1 = 1, mass2 = 1;
    double newXVel1 = (obj1->getXVel() * (mass1 - mass2) + 2 * mass2 * obj2->getXVel()) / mass1 + mass2;
    double newYVel1 = (obj1->getYVel() * (mass1 - mass2) + 2 * mass2 * obj2->getYVel()) / mass1 + mass2;
    double newXVel2 = (obj2->getXVel() * (mass2 - mass1) + 2 * mass1 * obj1->getXVel()) / mass1 + mass2;
    double newYVel2 = (obj2->getYVel() * (mass2 - mass1) + 2 * mass1 * obj1->getYVel()) / mass1 + mass2;

    obj1->setXVel(newXVel1);
    obj1->setYVel(newYVel1);
    //obj2->setXVel(newXVel2);
    //obj2->setYVel(newYVel2);


//    Vector2D vel1(obj1->getXVel(), obj1->getYVel());
//    Vector2D vel2(obj2->getXVel(), obj2->getYVel());
//    Vector2D collision(hb2->getCenterX() - hb1->getCenterX(),
//                       hb2->getCenterY() - hb1->getCenterY());
//    collision.normalize();
//    double aci = vel1.scalarProduct(collision);
//    double bci = vel2.scalarProduct(collision);
//
//    // This process is more complex if weight is not equal
//    double acf = bci;
//    double bcf = aci;
//
//    vel1 = vel1 + collision * (acf - aci);
//    obj1->setXVel(vel1.getX());
//    obj1->setYVel(vel1.getY());
//    obj2->setXVel(vel2.getX());
//    obj2->setYVel(vel2.getY());
}

void CollisionManager::resolveAttackHurtbox(MapObject* obj1, AttackHitbox* hb1,
                                            MapObject* obj2, Hurtbox* hb2) {
    double launchAngle = hitbox_rel_angle(hb2, hb1) + hb1->getLaunchAngle() - 90;
    std::cout << launchAngle << std::endl;
    obj2->applyForce(hb1->getLaunch(), launchAngle);
}

void CollisionManager::GameUpdated() {
    checkCollisions();
}

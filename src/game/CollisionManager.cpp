#include "CollisionManager.h"

#include <iostream>
#include "Vector2D.h"

CollisionManager::CollisionManager(std::vector<MapObject*>* mapObjects) :
    _mapObjects(mapObjects) {
}

void CollisionManager::checkCollisions() {
    /*
        This method simply iterates over all hitboxes and checks for collision
        with the hitboxes of all other MapObjects in the game.
        If necessary (if there are many objects on the screen at the same time),
        I will implement a quad-tree algorithm to optimize this control.
    */
    for (unsigned int i = 0; i < _mapObjects->size() - 1; ++i) {
        for (unsigned int j = i + 1; j < _mapObjects->size(); ++j) {
            MapObject* temp1 = _mapObjects->at(i);
            MapObject* temp2 = _mapObjects->at(j);
            for (unsigned int a = 0; a < temp1->getHitboxes().size(); ++a) {
                for (unsigned int b = 0; b < temp2->getHitboxes().size(); ++b) {
                    Hitbox* hb1 = temp1->getHitboxes().at(a);
                    Hitbox* hb2 = temp2->getHitboxes().at(b);
                    if (hitbox_collision(hb1, hb2)) {
                        // Resolve collision between two hitboxes
                        resolveCollision(temp1, hb1, temp2, hb2);
                    }
                }
            }
        }
    }
}

/**
 * See header file for important notes on this method.
 */
void CollisionManager::resolveCollision(MapObject* obj1, Hitbox* hb1, MapObject* obj2, Hitbox* hb2) {
    HitboxType type1 = hb1->getHitboxType();
    HitboxType type2 = hb2->getHitboxType();
    // Perform actions depending on which types of hitboxes collide
    if (type1 == HitboxType::HURTBOX &&
        type2 == HitboxType::HURTBOX) {
        // Both are Hurtboxes
        Hurtbox* box1 = static_cast<Hurtbox*>(hb1);
        Hurtbox* box2 = static_cast<Hurtbox*>(hb2);
        resolveDoubleHurtbox(obj1, box1, obj2, box2);

    } else if (type1 == HitboxType::HURTBOX &&
               type2 == HitboxType::ATTACK) {
        // One is AttackHitbox, the other is Hurtbox
        AttackHitbox* box1 = static_cast<AttackHitbox*>(hb2);
        Hurtbox* box2 = static_cast<Hurtbox*>(hb1);
        resolveAttackHurtbox(obj1, box1, obj2, box2);

    } else if (type1 == HitboxType::ATTACK &&
               type2 == HitboxType::HURTBOX) {
        // One is Hurtbox, the other is AttackHitbox
        AttackHitbox* box1 = static_cast<AttackHitbox*>(hb1);
        Hurtbox* box2 = static_cast<Hurtbox*>(hb2);
        resolveAttackHurtbox(obj1, box1, obj2, box2);

    } else if (type1 == HitboxType::ATTACK &&
               type2 == HitboxType::ATTACK){
        // Both are AttackHitboxes
        AttackHitbox* box1 = static_cast<AttackHitbox*>(hb1);
        AttackHitbox* box2 = static_cast<AttackHitbox*>(hb2);
        resolveDoubleAttack(obj1, box1, obj2, box2);
    } else if (type1 == HitboxType::HURTBOX &&
               type2 == HitboxType::WALL) {
        // One is Hurtbox, the other is WallHitbox
        WallHitbox* box1 = static_cast<WallHitbox*>(hb1);
        Hurtbox* box2 = static_cast<Hurtbox*>(hb2);
        resolveWallHurtbox(obj1, box1, obj2, box2);
    } else {
        std::cout << "Hitbox not specified in CollisionManager::resolveCollision" << std::endl;
    }
}

void CollisionManager::resolveDoubleHurtbox(MapObject* obj1, Hurtbox* hb1,
                                            MapObject* obj2, Hurtbox* hb2) {

    // Very simple bouncing simulation, utilizing the property of total elastic collision
    // The resulting angles are not entirely correct at this point
    double mass1 = 2, mass2 = 1; // Mass should be determined in each MapObject later
    Vector2D vel1(obj1->getXVel(), obj1->getYVel());
    Vector2D vel2(obj2->getXVel(), obj2->getYVel());
    // Calculate the new velocities
    Vector2D newVel1 = (vel1 * (mass1 - mass2) + vel2 * 2 * mass2) / (mass1 + mass2);
    Vector2D newVel2 = (vel2 * (mass2 - mass1) + vel1 * 2 * mass1) / (mass1 + mass2);

    // Set new velocities
    obj1->setXVel(newVel1.getX());
    obj1->setYVel(newVel1.getY());
    obj2->setXVel(newVel2.getX());
    obj2->setYVel(newVel2.getY());

    /**
     * Below is a councing implementation that contains some error,
     * making it behave in a poor manner. I am keeping it here until
     * I figure out the problem.
     */
//    Vector2D vel1(obj1->getXVel(), obj1->getYVel());
//    Vector2D vel2(obj2->getXVel(), obj2->getYVel());
//    Vector2D collision(hb2->getCenterX() - hb1->getCenterX(),
//                       hb2->getCenterY() - hb1->getCenterY());
//    collision.normalize();
//    double aci = vel1.scalarProduct(collision);
//    double bci = vel2.scalarProduct(collision);
//
//     This process is more complex if weight is not equal
//    double acf = bci;
//    double bcf = aci;
//
//    vel1 = vel1 + collision * (acf - aci);
//    obj1->setXVel(vel1.getX());
//    obj1->setYVel(vel1.getY());
//    std::cout << vel2.getX() << " " << vel2.getY() << std::endl;
//    obj2->setXVel(vel2.getX());
//    obj2->setYVel(vel2.getY());
}

void CollisionManager::resolveDoubleAttack(MapObject* obj1, AttackHitbox* hb1,
                                           MapObject* obj2, AttackHitbox* hb2){
    // NOT IMPLEMENTED
}

void CollisionManager::resolveAttackHurtbox(MapObject* obj1, AttackHitbox* hb1,
                                            MapObject* obj2, Hurtbox* hb2) {
    double launchAngle = hitbox_rel_angle(hb2, hb1) + hb1->getLaunchAngle() - 90;
    obj2->applyForce(hb1->getLaunch(), launchAngle);
}


void CollisionManager::resolveWallHurtbox(MapObject* obj1, WallHitbox* hb1,
                                          MapObject* obj2, Hurtbox* hb2) {
    // A very simple and not really realistic bouncing method: reverse the velocities
    obj1->setXVel(obj1->getXVel() * -1);
    obj1->setYVel(obj1->getYVel() * -1);
}

void CollisionManager::GameUpdated() {
    checkCollisions();
}

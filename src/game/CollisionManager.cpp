#include "CollisionManager.h"

#include <iostream>

CollisionManager::CollisionManager(std::vector<MapObject*>* mapObjects) :
    _mapObjects(mapObjects) {
}

void CollisionManager::checkCollisions() {
//    for (unsigned int i = 0; i < _mapObjects->size() - 1; ++i) {
//        MapObject* temp1 = _mapObjects->at(i);
//        MapObject* temp2 = _mapObjects->at(i + 1);
//        for (unsigned int j = 0; j < temp1->getHitboxes().size(); ++j) {
//            for (unsigned int k = 0; k < temp2->getHitboxes().size(); ++k) {
//                if (hitbox_collision(temp1->getHitboxes().at(j), temp2->getHitboxes().at(k))) {
//                    std::cout << "COLLISION" << std::endl;
//                }
//            }
//        }
//    }

    MapObject* temp1 = _mapObjects->at(0);
    MapObject* temp2 = _mapObjects->at(1);
    Hitbox hb1 = temp1->getHitboxes().at(0);
    Hitbox hb2 = temp2->getHitboxes().at(0);

    const Circle c1(hb1.getAbsoluteX(temp1->getX()), hb1.getAbsoluteY(temp1->getY()), hb1.getRadius());
    const Circle c2(hb2.getAbsoluteX(temp2->getX()), hb2.getAbsoluteY(temp2->getY()), hb2.getRadius());
    if (circle_intersect(c1, c2)) std::cout << "COLLISION" << std::endl;
}

void CollisionManager::GameUpdated() {
    checkCollisions();
}

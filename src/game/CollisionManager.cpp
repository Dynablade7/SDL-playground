#include "CollisionManager.h"

#include <iostream>

CollisionManager::CollisionManager(std::vector<MapObject*>* mapObjects) :
    _mapObjects(mapObjects) {
}

void CollisionManager::checkCollisions() {
    for (unsigned int i = 0; i < _mapObjects->size() - 1; ++i) {
        MapObject* temp1 = _mapObjects->at(i);
        MapObject* temp2 = _mapObjects->at(i + 1);
        for (unsigned int j = 0; j < temp1->getHitboxes().size(); ++j) {
            for (unsigned int k = 0; k < temp2->getHitboxes().size(); ++k) {
                if (hitbox_collision(temp1->getHitboxes().at(j), temp1->getX(), temp1->getY(),
                                     temp2->getHitboxes().at(k), temp2->getX(), temp2->getY())) {
                                        std::cout << "COLLISION" << std::endl;
                                     }
            }
        }

    }
}

void CollisionManager::GameUpdated() {
    checkCollisions();
}

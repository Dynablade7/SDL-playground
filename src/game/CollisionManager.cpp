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
                Hitbox* hb1 = temp1->getHitboxes().at(j);
                Hitbox* hb2 = temp2->getHitboxes().at(k);
                if (hitbox_collision(hb1, hb2)) {
                    // If collision of hitboxes
                    temp1->resolveCollision(hb1, hb2, temp2);
                    temp2->resolveCollision(hb2, hb1, temp1);
                }
            }
        }

    }
}

void CollisionManager::GameUpdated() {
    checkCollisions();
}

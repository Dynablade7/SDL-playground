#include "CollisionManager.h"

#include "CollisionAttributes.h"
#include "MapObject.h"
#include "Vector2D.h"

CollisionManager::CollisionManager(std::vector<MapObject*>* mapObjects) :
    _mapObjects(mapObjects) {
}

void CollisionManager::checkCollisions() {
    // Iterate over all MapObjects and their hitboxes
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
                        CollisionAttributes c1 = hb1->resolveCollision(hb2, temp1, temp2);
                        CollisionAttributes c2 = hb2->resolveCollision(hb1, temp2, temp1);
                        // Commit any changes that were made to the two MapObjects (velocity etc)
                        // See CollisionAttributes class documentation for details.
                        c1.commitChanges();
                        c2.commitChanges();

                    }
                }
            }
        }
    }
}

void CollisionManager::GameUpdated() {
    checkCollisions();
}

#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include <vector>
#include "GameUpdatedListener.h"
#include "AttackHitbox.h"
#include "Hurtbox.h"
#include "MapObject.h"
#include "WallHitbox.h"

/**
 * An instance of this object is used to check for collisions between
 * the hitboxes of the game's MapObjects.
 *
 * This is done by iterating over all hitboxes of all MapObjects in the game
 * and checking whether they are intersecting. If the ammount of hitboxes in the
 * game turns out to be high, a quad-tree algorithm will be implemented to
 * optimize this step. The type of the colliding hitboxes is then checked,
 * and action is taken accordingly. See documentation of the resolveCollision method
 * for details on this.
 */
class CollisionManager : public GameUpdatedListener {
    public:

        /**
         * Constructor.
         * @param mapObjects - A pointer to a vector containing all the game's
         * MapObjects. These are used for collision detection.
         */
        CollisionManager(std::vector<MapObject*>* mapObjects);

        /**
         * Method derived from GameUpdatedListener.
         * This method is called whenever the game is updated and the game should
         * be checked for collisions. Utilizing the Observer design pattern.
         */
        void GameUpdated();

    private:

        /**
         * Checks for collisions between all hitboxes of all MapObject
         * currently in the game.
         * Runs in O(n^2) time, where n is the total number of hitboxes across
         * all MapObjects.
         * I will probably implement a quad-tree algorithm later to optimize
         * collision management.
         */
        void checkCollisions();

        /**
         * When there is a collision betweenn two hitboxes, this method
         * resolves it depending on what type of hitboxes collide.
         * @param obj1 - A pointer to one of the colliding MapObjects
         * @param hb1 - A pointer to the hitbox belonging to obj1
         * @param obj2 - A pointer to one of the colliding MapObjects
         * @param hb2 - A pointer to the hitbox belonging to obj2
         *
         * ---- NEEDS REDISIGNING -------------------------------------------------
         * This method simply checks what type of hitboxes are colliding, casts them
         * to the specific type, and then acts according to that.
         * I would like to implement this polymorphically, but I have not quite
         * figured out how yet. This solution works for a few different types of
         * hitboxes, but does not scale very well, neither is it very safe.
         * ------------------------------------------------------------------------
         */
        void resolveCollision(MapObject* obj1, Hitbox* hb1,
                              MapObject* obj2, Hitbox* hb2);

        /**
         * This method takes care of the case when two Hurtboxes collide.
         * Essentially, the two MapObjects will bounce off each other.
         * @param obj1 - A pointer to one of the colliding MapObjects
         * @param hb1 - A pointer to the hitbox belonging to obj1
         * @param obj2 - A pointer to one of the colliding MapObjects
         * @param hb2 - A pointer to the hitbox belonging to obj2
         */
        void resolveDoubleHurtbox(MapObject* obj1, Hurtbox* hb1,
                                  MapObject* obj2, Hurtbox* hb2);

        /**
         * NOT IMPLEMENTED
         */
        void resolveDoubleAttack(MapObject* obj1, AttackHitbox* hb1,
                                 MapObject* obj2, AttackHitbox* hb2);

        /**
         * Resolves collision between an AttackHitbox and a Hurtbox.
         * The owner of the Hurtbox is launched and damaged depending
         * on the specs of the AttackHitbox.
         * @param obj1 - A pointer to one of the colliding MapObjects
         * @param hb1 - A pointer to the hitbox belonging to obj1
         * @param obj2 - A pointer to one of the colliding MapObjects
         * @param hb2 - A pointer to the hitbox belonging to obj2
         */
        void resolveAttackHurtbox(MapObject* obj1, AttackHitbox* hb1,
                                  MapObject* obj2, Hurtbox* hb2);

        /**
         * Resolves collision between an WallHitbox and a Hurtbox.
         * The owner of the hurtbox bounces off the wall.
         * @param obj1 - A pointer to one of the colliding MapObjects
         * @param hb1 - A pointer to the hitbox belonging to obj1
         * @param obj2 - A pointer to one of the colliding MapObjects
         * @param hb2 - A pointer to the hitbox belonging to obj2
         */
        void resolveWallHurtbox(MapObject* obj1, WallHitbox* hb1,
                                MapObject* obj2, Hurtbox* hb2);

        std::vector<MapObject*>* _mapObjects = nullptr;
};

#endif // COLLISIONMANAGER_H

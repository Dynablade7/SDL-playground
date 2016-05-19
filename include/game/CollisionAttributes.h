#ifndef COLLISIONATTRIBUTES_H
#define COLLISIONATTRIBUTES_H

// Forward declarations
class Vector2D;
class MapObject;

/**
 * An instance of this object is returned from the Hitbox class'
 * resolveCollision method. Any changes to a colliding MapObject is registered
 * in that object (such as a change of velocity when bouncing off a wall).
 * When the object's commitChanges method is called, all changes are applied.
 *
 * The reason for this design is that each of the two colliding hitboxes register
 * the collision sequentially - the second one will not calculate the collidion until after
 * the first one is finished. As a result of this, it is not possible to change the
 * MapObject that has the first hitbox until after the second is also done, as this would
 * result in a different situation from the actual collision. This design allows all changes
 * to be applied after both collisions are calculated.
 */
class CollisionAttributes {
    public:

        /**
         * Constructor.
         * @param obj - The MapObject to apply changes to
         */
        CollisionAttributes(MapObject* obj);

        /**
         * Destructor.
         */
        ~CollisionAttributes();

        /**
         * Applies the changes that are made to the MapObject on collision.
         */
        void commitChanges();

        /**
         * Sets the velocity that the MapObject will get when commitChanges is called.
         */
        void setVelocity(Vector2D* newVel);

        /**
         * Sets the force that will be applied to the MapObject when commitChanges is called.
         * @param force - The force that will be applied
         * @param angle - The angle at which the force will be applied
         */
        void setForce(double force, double angle);

    private:

        /**
         * The MapObject that changes will be applied to when calling commitChanges
         */
        MapObject* _obj;

        /**
         * The new velocity of the MapObject
         */
        Vector2D* _newVel = nullptr;

        /**
         * The force that will be applied and at which angle
         */
        double _force, _angle;

        /**
         * Boolean values stating wether certain changes have been made.
         * For instance, when setVelocity is called, _velChanged is set to true.
         */
        bool _velChanged = false, _forceApplied = false;
};

#endif // COLLISIONATTRIBUTES_H

#ifndef HITBOX_H
#define HITBOX_H

// Forward declarations
class AttackHitbox;
class CollisionAttributes;
class Hurtbox;
class MapObject;
class WallHitbox;

/**
 * Enum representing the type of hitbox.
 * This is used when checking for collisions - different types
 * colliding have different results.
 */
enum class HitboxType {HURTBOX, ATTACK, SHIELD, WALL};

/**
 * The abstract base class for all hitboxes in the game.
 * Hitboxes are the basic units used for collision control. Each MapObject
 * has a number of different hitboxes attatched to them which are used when
 * checking if it collides with another MapObject.
 *
 * Each hitbox is basically a circle with different attributes depending on
 * what type of hitbox it is. The type of Hitbox is defined as one of the
 * HitboxTypes (see Enum class above) in the respective subclass' constructor.
 *
 * A point of interest in this class is the public resolveCollision method that
 * is called whenever a collision is detected. This method checks what type of hitbox
 * it collided with and calls one of the private pure virtual versions of resolveCollision.
 * These are implemented in each subclass, since collisions between different Hitbox
 * types result different behaviour.
 */
class Hitbox {
    public:

        /**
         * Constructor.
         * @param x - The absolute x position of the hitbox' "upper left corner"
         * @param y - The absolute y position of the hitbox' "upper left corner"
         * @param xRel - The x position of the Hitbox' "upper left corner", relative
         * to the MapObject that created it.
         * @param yRel - The y position of the Hitbox' "upper left corner", relative
         * to the MapObject that created it.
         * @param radius - The hitbox' radius.
         * @param hitboxType - The type of the hitbox, specified in each subclass' constructor.
         */
        Hitbox(double x, double y, double xRel, double yRel, int radius, HitboxType hitboxType);

        /**
         * Destructor.
         */
        virtual ~Hitbox();

        /**
         * When the MapObject that the hitbox is attatched to moves, this function
         * is called to update the hotbox' position.
         */
        void updatePos(double x, double y);

        /**
         * Changes the position of the hitbox in relation to the MapObject it is attatched to.
         * It is used when the MapObject rotates. Trigonometric functions are used to calculate
         * the new x and y values.
         * @param angle - The number of degrees that the MapObject is rotated.
         */
        void updateRelativePos(double angle);

        /**
         * This method is called when a collition is detected. A switch case is used
         * to find which type of hitbox is colliding with this one, and according to
         * that, the corresponding pure virtual function is called, delegating the collision
         * management to each specific subclass.
         * @param hb - The hitbox that collides with this hitbox
         * @param obj1 - The MapObject that this Hitbox is attatched to
         * @param obj2 - The MapObject that hb is attatched to
         * @return A CollisionAttributes object specifying any change that is to be
         * made to obj1 (see CollisionAttributes class documentation for details)
         */
        virtual CollisionAttributes resolveCollision(Hitbox* hb,
                                                     MapObject* obj1, MapObject* obj2);

        double getX(), getY();

        /**
         * Returns the absolute x/y value of the hitbox' center.
         * In practice, the value returned is [_x/_y] + _radius, respectively.
         */
        double getCenterX(), getCenterY();

        int getRadius();

        HitboxType getHitboxType();

    protected:

        /**
         * The absolute x/y values of the hitbox' "upper left corner".
         * To get the x/y values of the hitbox' center, simply add _radius.
         * This is done in the class' getCenter[X/Y]() methods.
         */
        double _x, _y;

        /**
         * The hitbox' position relative to the center of the MapObject it is attatched to.
         */
        double _xRel, _yRel;

        /**
         * The radius of the hitbox.
         */
        int _radius;

        /**
         * The angle relative to the center point of the MapObject the hitbox is attatched to.
         * The center of the hitbox is used.
         */
        double _angle;

        /**
         * The distance between the center of the hitbox and the center of the MapObject it is attatched to.
         */
        double _dist;

        /**
         * The type of the hitbox.
         */
        const HitboxType _hitboxType;

        /**
         * Resolves collision between this hitbox and a Hurtbox.
         * @param hb - The hitbox that collides with this hitbox
         * @param obj1 - The MapObject that this Hitbox is attatched to
         * @param obj2 - The MapObject that hb is attatched to
         * @return A CollisionAttributes object specifying any change that is to be
         * made to obj1 (see CollisionAttributes class documentation for details)
         */
        virtual CollisionAttributes resolveHurtboxCollision(Hurtbox* hb,
                                                            MapObject* obj1, MapObject* obj2) = 0;

        /**
         * Resolves collision between this hitbox and an AttackHitbox.
         * @param hb - The hitbox that collides with this hitbox
         * @param obj1 - The MapObject that this Hitbox is attatched to
         * @param obj2 - The MapObject that hb is attatched to
         * @return A CollisionAttributes object specifying any change that is to be
         * made to obj1 (see CollisionAttributes class documentation for details)
         */
        virtual CollisionAttributes resolveAttackCollision(AttackHitbox* hb,
                                                           MapObject* obj1, MapObject* obj2) = 0;

        /**
         * Resolves collision between this hitbox and a WallHitbox.
         * @param hb - The hitbox that collides with this hitbox
         * @param obj1 - The MapObject that this Hitbox is attatched to
         * @param obj2 - The MapObject that hb is attatched to
         * @return A CollisionAttributes object specifying any change that is to be
         * made to obj1 (see CollisionAttributes class documentation for details)
         */
        virtual CollisionAttributes resolveWallCollision(WallHitbox* hb,
                                                         MapObject* obj1, MapObject* obj2) = 0;
};

/**
 * Checks whether there is a collision between hb1 and hb2 by checking
 * if their circles intersect.
 * @return true if collision, else false.
 */
bool hitbox_collision(Hitbox* hb1, Hitbox* hb2);

/**
 * The angle between two hitboxes, relative to hb1.
 * This should be used when two hitboxes collide, to check where they
 * are located in relation to each other.
 */
double hitbox_rel_angle(Hitbox* hb1, Hitbox* hb2);

#endif // HITBOX_H

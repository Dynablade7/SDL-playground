#ifndef HITBOX_H
#define HITBOX_H

/**
 * Enum representing the type of hitbox.
 * This is used when checking for collisions - different types
 * colliding have different results.
 */
enum class HitboxType {HURTBOX, ATTACK, SHIELD};

/**
 * A class to represent hitboxes of the MapObjects in the game.
 * Each hitbox is basically a circle, with some additional attributes to be
 * added later, such as damage, launch rate, etc (currently unipmlemented).
 * Hitboxes will be the main focus when dealing with collisions between MapObjects.
 */
class Hitbox {
    public:

        /**
         * Constructor. This constructor creates a circle object from the
         * arguments passed to the function and assigns that circle to the hitbox.
         * @param x - The x position of the circle's "upper left corner"
         * @param y - The y position of the circle's "upper left corner"
         * @param radius - The circle's radius.
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
         * Returns the x/y value of the hitbox' "upper left corner" relative to the
         * center point of the MapObject it is attatched to.
         */
        double getX(), getY();

        /**
         * Returns the x/y value of the hitbox' center relative to the center point
         * of the MapObject it is attatched to.
         */
        double getCenterX(), getCenterY();

        int getRadius();

        HitboxType getHitboxType();

    protected:

        double _x, _y;

        /**
         * The hitbox' position relative to the center of the MapObject it is attatched to.
         */
        double _xRel, _yRel;
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

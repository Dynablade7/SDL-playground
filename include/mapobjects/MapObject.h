#ifndef MAPOBJECT_H
#define MAPOBJECT_H

#include <vector>
#include "SDL.h"

// Forward declarations
class Hitbox;
class Sprite;

/**
 * The abstract base class of all MapObjects. MapObjects are basically all
 * moving/interactable objects on the map, including player, enemies, powerups and whatnot.
 *
 * Each MapObject has information about position, speed and direction. It also holds a pointer
 * to a Sprite object.
 * To move a MapObject, the moveObject method is called every tick.
 * To change the current velocity, the applyForce method is used.
 *
 * Collisions between MapObjects are managed with the use of Hitbox objects.
 * Each MapObject has a set of hitboxes that make the different MapObjects
 * interact with each other when the hitboxes intersect with each other.
 */
class MapObject {
    public:

        MapObject(int x, int y, Sprite* sprite);
        virtual ~MapObject();
        MapObject(const MapObject& other);
        MapObject& operator=(const MapObject& other);

        /**
         * Changes the MapObject's position based on its current _xVel and _yVel values.
         */
        void moveObject();

        /**
         * Accelerates the MapObject in the specified direction.
         * @param force - The force that is applied to the PlayerShip
         * @param direction - The direction (degrees) that the PlayerShip is pushed towards.
         *        0 degrees -> vertical acceleration upwards
                  90 degrees -> horizontal acceleration to the left, etc
         */
        void applyForce(double force, double direction);

        /**
         * Draw the MapObject's sprite.
         * @param renderer - The SDL_Renderer to which the sprite is drawn
         * @param x - The x position to which the sprite is drawn
         * @param y - The y position to which the sprite is drawn
         * @param center - The point specifying the center of rotation.
         * @param flip - Enum specifying if and how the sprite is flipped.
         */
        void draw(SDL_Renderer* renderer, int x, int y, SDL_Point* center = nullptr,
                  SDL_RendererFlip flip = SDL_FLIP_NONE);

        /**
         * A method used for displaying hitboxes when debugging.
         * @param renderer - The SDL_Renderer to which the hitbox' sprite is drawn
         * @param hitboxSprite - The Sprite representing a hitbox.
         */
        void drawHitboxes(SDL_Renderer* renderer, Sprite* hitboxSprite);

        double getX(), getY();
        double getXVel(), getYVel();
        void setXVel(double xVel), setYVel(double yVel);

        /**
         * Returns the center x/y values of the MapObject, relative to its
         * current x/y position. In practice, the return value is the sprite's
         * width/height divided by 2, respectively.
         * To get the absolute center point of the MapObject, use
         * get[X/Y]() + getCenter[X/Y]().
         */
        double getCenterX(), getCenterY();
        std::vector<Hitbox*> getHitboxes();

    protected:

        /**
         * The position of the MapObject.
         */
        double _x, _y;

        /**
         * The horizontal and vertical velocity of the MapObject.
         */
        double _xVel, _yVel;

        /**
         * The direction (in degrees) that the MapObject is facing. Default is 0.
         * Add to rotate clockwise, subtract to rotate counter-clockwise.
         */
        double _direction;

        /**
         * The sprite belonging to the MapObject.
         */
        Sprite* _sprite = nullptr;

        /**
         * This pure virtual method is called in each MapObject's constructor (unless
         * that specific MapObject does not have any hitboxes). It creates the Hitboxes
         * associated with each MapObject that are used for collision handling.
         *
         * Different types of hitboxes interact with each other in different ways.
         */
        virtual void generateHitboxes() = 0;

        /**
         * Rotates the MapObject by the specified amount of degrees.
         * Positive for clockwise, negative for counter-clockwise.
         * It also repositions the hitboxes of the MapObject in accordance
         * to the rotation.
         */
        void rotateDeg(double angle);

        /**
         * A vector of all hitboxes associated with the MapObject.
         */
        std::vector<Hitbox*> _hitboxes;
};

#endif // MAPOBJECT_H

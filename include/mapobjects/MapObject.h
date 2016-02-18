#ifndef MAPOBJECT_H
#define MAPOBJECT_H

#include <SDL.h>
#include "Sprite.h"

/**
 * This will be the base class of all map objects, including player,
 * enemies and whatnot.
 */
class MapObject {
    public:
        MapObject(int x, int y, Sprite* sprite);
        virtual ~MapObject();
        MapObject(const MapObject& other);
        MapObject& operator=(const MapObject& other);

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
        int getX();
        int getY();
    protected:
        int _x, _y;

        /**
         * The angle (number of degrees) that the MapObject's sprite will be rotated to
         * when drawn, relative to its starting position.
         */
        double angle;
        Sprite* _sprite = nullptr;
};

#endif // MAPOBJECT_H

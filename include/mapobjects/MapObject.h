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
         */
        void draw(SDL_Renderer* renderer, int x, int y);
        int getX();
        int getY();
    protected:
        int _x, _y;
        Sprite* _sprite = nullptr;
};

#endif // MAPOBJECT_H

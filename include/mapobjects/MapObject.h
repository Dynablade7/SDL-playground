#ifndef MAPOBJECT_H
#define MAPOBJECT_H

#include <SDL.h>
#include "Sprite.h"

/**
 * This will be the super class of all map objects, including player,
 * enemies and whatnot.
 * << Not implemented >>
 */
class MapObject {
    public:
        MapObject(int x, int y, Sprite* sprite);
        virtual ~MapObject();
        MapObject(const MapObject& other);
        MapObject& operator=(const MapObject& other);
        void draw(SDL_Renderer* renderer, int x, int y);
        int getX();
        int getY();
    protected:
        int _x, _y;
        Sprite* _sprite = nullptr;
};

#endif // MAPOBJECT_H

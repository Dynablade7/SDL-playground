#ifndef MAPOBJECT_H
#define MAPOBJECT_H

#include "Sprite.h"

/**
 * This will be the super class of all map objects, including player,
 * enemies and whatnot.
 * << Not implemented >>
 */
class MapObject {
    public:
        MapObject();
        virtual ~MapObject();
        MapObject(const MapObject& other);
        MapObject& operator=(const MapObject& other);
    protected:
        int x, y;
        Sprite* sprite = nullptr;
};

#endif // MAPOBJECT_H

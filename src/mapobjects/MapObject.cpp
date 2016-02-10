#include "MapObject.h"

MapObject::MapObject(int x, int y, Sprite* sprite) : _x(x), _y(y), _sprite(sprite) {
    //ctor
}

MapObject::~MapObject() {
    //dtor
}

MapObject::MapObject(const MapObject& other) {
    //copy ctor
}

MapObject& MapObject::operator=(const MapObject& rhs) {
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

void MapObject::draw(SDL_Renderer* renderer, int x, int y) {
    // Draw the MapObject's sprite to the screen.
    if (_sprite != nullptr) {
        _sprite->draw(renderer, x, y);
    }
}

int MapObject::getX() {
    return _x;
}

int MapObject::getY() {
    return _y;
}

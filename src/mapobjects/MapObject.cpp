#include "MapObject.h"

MapObject::MapObject(int x, int y, Sprite* sprite) : _x(x), _y(y), _sprite(sprite) {
}

MapObject::~MapObject() {
}

MapObject::MapObject(const MapObject& other) {
}

MapObject& MapObject::operator=(const MapObject& rhs) {
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

void MapObject::draw(SDL_Renderer* renderer, int x, int y, SDL_Point* center,
                     SDL_RendererFlip flip) {
    // Draw the MapObject's sprite to the screen.
    if (_sprite != nullptr) {
        _sprite->draw(renderer, x, y, angle, center, flip);
    }
}

int MapObject::getX() {
    return _x;
}

int MapObject::getY() {
    return _y;
}

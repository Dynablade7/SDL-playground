#include "MapObject.h"
#include "MathFunctions.h"

MapObject::MapObject(int x, int y, Sprite* sprite) :
     _x(x), _y(y), _sprite(sprite) {
}

MapObject::~MapObject() {
}

MapObject::MapObject(const MapObject& other) {
}

MapObject& MapObject::operator=(const MapObject& rhs) {
    if (this == &rhs) return *this;
    return *this;
}

void MapObject::draw(SDL_Renderer* renderer, int x, int y, SDL_Point* center,
                     SDL_RendererFlip flip) {
    // Draw the MapObject's sprite to the screen.
    if (_sprite != nullptr) {
        _sprite->draw(renderer, x, y, _direction, center, flip);
    }
}

void MapObject::drawHitboxes(SDL_Renderer* renderer, Sprite* hitboxSprite) {
    for (unsigned int i = 0; i < _hitboxes.size(); ++i) {
        Hitbox hb = _hitboxes.at(i);
        // Draw each hitbox
        hitboxSprite->drawResized(renderer, hb.getAbsoluteX(_x + getCenter().x), hb.getAbsoluteY(_y + getCenter().y),
                                  hb.getRadius() * 2, hb.getRadius() * 2);
    }
}

void MapObject::moveObject() {
    _x += _xVel;
    _y -= _yVel;
}

void MapObject::applyForce(double force, double direction) {
    _yVel += math_cos(direction, force);
    _xVel += math_sin(direction, force);
}

void MapObject::rotateDeg(double angle) {
    _direction += angle;
    // Reposition all hitboxes
    Hitbox* hb = nullptr;
    for (unsigned int i = 0; i < _hitboxes.size(); ++i) {
        hb = &_hitboxes.at(i);
        hb->updatePos(angle);
    }
    hb = nullptr;
}

SDL_Point MapObject::getCenter() {
    return _sprite->getCenter();
}

double MapObject::getX() {
    return _x;
}

double MapObject::getY() {
    return _y;
}

std::vector<Hitbox> MapObject::getHitboxes() {
    return _hitboxes;
}

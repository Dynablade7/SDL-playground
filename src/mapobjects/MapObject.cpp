#include "MapObject.h"

#include <iostream>
#include <typeinfo>
#include "Hurtbox.h"
#include "AttackHitbox.h"
#include "MathFunctions.h"

MapObject::MapObject(int x, int y, Sprite* sprite) :
     _x(x), _y(y), _sprite(sprite) {
}

MapObject::~MapObject() {
    // Deallocate all hitboxes attatched to the MapObject
    for (unsigned int i = 0; i < _hitboxes.size(); ++i) {
        delete _hitboxes.at(i);
        _hitboxes.at(i) = nullptr;
    }
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
        // Draw each hitbox
        Hitbox* hb = _hitboxes.at(i);
        hitboxSprite->drawResized(renderer, hb->getX(), hb->getY(),
                                  hb->getRadius() * 2, hb->getRadius() * 2);
    }
}

void MapObject::onCollision(Hitbox* myHb, Hitbox* otherHb) {
    // Perform actions depending on which types of hitboxes collide.
    switch (myHb->getHitboxType()) {
    case HitboxType::HURTBOX:
    {
        Hurtbox* hb1 = static_cast<Hurtbox*>(myHb);
        HitboxType otherType = otherHb->getHitboxType();
        if (otherType == HitboxType::HURTBOX) {
            //_xVel = -_xVel;
            //_yVel = -_yVel;
        } else if (otherType == HitboxType::ATTACK) {
            AttackHitbox* hb2 = static_cast<AttackHitbox*>(otherHb);
            double launchAngle = hitbox_rel_angle(hb1, hb2) + hb2->getLaunchAngle() - 90;
            applyForce(hb2->getLaunch(), launchAngle);
        }
        break;
    }
    case HitboxType::ATTACK:
        break;
    default:
        std::cout << "Hitbox not specified in MapObject::onCollision" << std::endl;
    }
}

void MapObject::moveObject() {
    _x += _xVel;
    _y -= _yVel;
    // Update the position of all the MapObject's hitboxes
    for (unsigned int i = 0; i < _hitboxes.size(); ++i) {
        _hitboxes.at(i)->updatePos(_x + getCenterX(), _y + getCenterY());
    }
}

void MapObject::applyForce(double force, double direction) {
    _yVel += math_cos(direction, force);
    _xVel += math_sin(direction, force);
}

void MapObject::rotateDeg(double angle) {
    _direction += angle;
    // Update the relative position of all the MapObject's hitboxes
    for (unsigned int i = 0; i < _hitboxes.size(); ++i) {
        _hitboxes.at(i)->updateRelativePos(angle);
    }
}

double MapObject::getX() {
    return _x;
}

double MapObject::getY() {
    return _y;
}

double MapObject::getCenterX() {
    return _sprite->getCenterX();
}

double MapObject::getCenterY() {
    return _sprite->getCenterY();
}

std::vector<Hitbox*> MapObject::getHitboxes() {
    return _hitboxes;
}

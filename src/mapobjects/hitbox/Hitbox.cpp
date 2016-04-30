#include "Hitbox.h"
#include "MathFunctions.h"

Hitbox::Hitbox(double x, double y, double xRel, double yRel, int radius, HitboxType hitboxType) :
    _x(x), _y(y), _xRel(xRel), _yRel(yRel), _radius(radius), _hitboxType(hitboxType) {
    // Calculate the distance from the center of the hitbox to the center of the MapObject
    _dist = math_calculateDist(_xRel + _radius, _yRel + _radius);
    // Calculate the initial angle
    _angle = math_atan2(_yRel + _radius, _xRel + _radius);
}

Hitbox::~Hitbox() {
}

void Hitbox::updatePos(double x, double y) {
    _x = x + _xRel;
    _y = y + _yRel;
}

void Hitbox::updateRelativePos(double angle) {
    _angle += angle;
    _xRel = math_cos(_angle, _dist) - _radius;
    _yRel = math_sin(_angle, _dist) - _radius;
}

double Hitbox::getX() {
    return _x;
}

double Hitbox::getY() {
    return _y;
}

double Hitbox::getCenterX() {
    return _x + _radius;
}

double Hitbox::getCenterY() {
    return _y + _radius;
}

int Hitbox::getRadius() {
    return _radius;
}

HitboxType Hitbox::getHitboxType() {
    return _hitboxType;
}

bool hitbox_collision(Hitbox* hb1, Hitbox* hb2) {
    double dist = math_calculateDist(hb1->getCenterX(), hb1->getCenterY(),
                                     hb2->getCenterX(), hb2->getCenterY());
    return (dist <= hb1->getRadius() + hb2->getRadius());
}


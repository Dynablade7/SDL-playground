#include "Hitbox.h"
#include "MathFunctions.h"

Hitbox::Hitbox(double x, double y, int radius, HitboxType hitboxType) :
    _x(x), _y(y), _radius(radius), _hitboxType(hitboxType) {
    // Calculate the distance from the center of the hitbox to the center of the MapObject
    _dist = math_calculateDist(getCenterX(), getCenterY());
    // Calculate the initial angle
    _angle = math_atan2(getCenterY(), getCenterX());
}

void Hitbox::updatePos(double angle) {
    _angle += angle;
    _x = math_cos(_angle, _dist) - _radius;
    _y = math_sin(_angle, _dist) - _radius;
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

double Hitbox::getAbsoluteX(double x) {
    return _x + x;
}

double Hitbox::getAbsoluteY(double y) {
    return _y + y;
}

int Hitbox::getRadius() {
    return _radius;
}

bool hitbox_collision(Hitbox* hb1, double x1, double y1, Hitbox* hb2, double x2, double y2) {
    double dist = math_calculateDist(hb1->getCenterX() + x1, hb1->getCenterY() + y1,
                                     hb2->getCenterX() + x2, hb2->getCenterY() + y2);
    return (dist <= hb1->getRadius() + hb2->getRadius());
}


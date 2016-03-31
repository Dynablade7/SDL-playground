#include "Hitbox.h"
#include <cmath>
#include "MathFunctions.h"

Hitbox::Hitbox(Circle c) :
    _circle(c) {
    init();
}

Hitbox::Hitbox(double x, double y, int radius) :
    _circle(x, y, radius) {
    init();
}

void Hitbox::updatePos(double angle) {
    _angle += angle;
    _circle.x = math_cos(_angle, _dist) - _circle.radius;
    _circle.y = math_sin(_angle, _dist) - _circle.radius;
}

void Hitbox::init() {
    // Calculate the distance from the center of the hitbox to the center of the MapObject
    _dist = math_calculateDist(getCenterX(), getCenterY());
    // Calculate the initial angle
    _angle = math_atan2(getCenterY(), getCenterX());
}

Circle Hitbox::getCircle() {
    return _circle;
}

double Hitbox::getX() {
    return _circle.x;
}

double Hitbox::getY() {
    return _circle.y;
}

double Hitbox::getCenterX() {
    return _circle.x + _circle.radius;
}

double Hitbox::getCenterY() {
    return _circle.y + _circle.radius;
}

double Hitbox::getAbsoluteX(double x) {
    return _circle.x + x;
}

double Hitbox::getAbsoluteY(double y) {
    return _circle.y + y;
}

int Hitbox::getRadius() {
    return _circle.radius;
}

bool hitbox_collision(Hitbox& hb1, Hitbox& hb2) {
    return circle_intersect(hb1.getCircle(), hb2.getCircle());
}

#include "Hitbox.h"
#include <cmath>

#define PI 3.14159265
#define radianConstant PI / 180 // To convert degrees to radians
#define degreeConstant 180 / PI // To convert radians to degrees

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
    _circle.x = _dist * cos(_angle * radianConstant) - _circle.radius;
    _circle.y = _dist * sin(_angle * radianConstant) - _circle.radius;
}

void Hitbox::init() {
    // Calculate the distance from the center of the hitbox to the center of the MapObject
    _dist = sqrt(pow(getCenterX(), 2) + pow(getCenterY(), 2));
    // Calculate the initial angle
    _angle = atan2(getCenterY(), getCenterX()) * degreeConstant
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

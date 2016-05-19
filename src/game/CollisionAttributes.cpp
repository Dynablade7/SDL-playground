#include "CollisionAttributes.h"

#include "MapObject.h"
#include "Vector2D.h"

CollisionAttributes::CollisionAttributes(MapObject* obj) :
    _obj(obj) {
}

CollisionAttributes::~CollisionAttributes() {
    // Delete the velocity vector - it will not be used beyond this point
    delete _newVel;
    _newVel = nullptr;
}

void CollisionAttributes::commitChanges() {
    if (_velChanged) {
        _obj->setXVel(_newVel->getX());
        _obj->setYVel(_newVel->getY());
    }
    if (_forceApplied) {
        _obj->applyForce(_force, _angle);
    }
}

void CollisionAttributes::setVelocity(Vector2D* newVel) {
    _newVel = newVel;
    _velChanged = true;
}

void CollisionAttributes::setForce(double force, double angle) {
    _force = force;
    _angle = angle;
    _forceApplied = true;
}

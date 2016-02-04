#include "MapObject.h"

MapObject::MapObject() {
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

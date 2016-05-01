#include "Vector2D.h"

#include <cmath>
#include "MathFunctions.h"

Vector2D::Vector2D(double x, double y) :
    _x(x), _y(y) {
}

double Vector2D::scalarProduct(const Vector2D& v2d) {
    return (_x * v2d.getX() + _y * v2d.getY());
}

Vector2D Vector2D::project(const Vector2D& v2d) {
    double projectConst = scalarProduct(v2d) / pow(v2d.getLenght(), 2);
    Vector2D result(v2d.getX() * projectConst, v2d.getY() * projectConst);
    return result;
}

Vector2D Vector2D::mirror(const Vector2D& v2d) {
    // Create a vector that is perpendicular to v2d
    Vector2D normal(v2d.getY() * -1, v2d.getX());
    Vector2D projection = project(normal);
    return *this - projection * 2;

}

double Vector2D::getX() const {
    return _x;
}

double Vector2D::getY() const {
    return _y;
}

double Vector2D::getLenght() const {
    return math_calculateDist(_x, _y);
}

Vector2D Vector2D::operator+(const Vector2D& v2d) {
    return Vector2D(_x + v2d.getX(), _y + v2d.getY());
}

Vector2D Vector2D::operator-(const Vector2D& v2d) {
    return Vector2D(_x - v2d.getX(), _y - v2d.getY());
}

Vector2D Vector2D::operator*(double t) {
    return Vector2D(_x * t, _y * t);
}

Vector2D Vector2D::operator/(double t) {
    return Vector2D(_x / t, _y / t);
}

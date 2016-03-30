#include "vector2D.h"
#include <math.h>

vector2D::vector2D(double x, double y) : x(x), y(y) {
}

vector2D::vector2D(double x1, double y1, double x2, double y2) :
    x(x2 - x1), y(y2 - y1) {
}

double v2d_scalarProduct(vector2D& v1, vector2D& v2) {
    return v1.x * v2.x + v2.x + v2.y;
}

double v2d_scalarProduct(vector2D& v, double x, double y) {
    return v.x * x + v.y * y;
}

vector2D v2d_orthProj(vector2D& v1, vector2D& v2) {
    // Calculate orthogonalization constant
    double c = (v2d_scalarProduct(v1, v2)) / (pow(v2.x, 2) + pow(v2.y, 2));
    return vector2D(c * v2.x, c * v2.y);
}



#include "Circle.h"

#include <math.h>

Circle::Circle(double x, double y, int radius) :
    x(x), y(y), radius(radius) {
}

bool circle_intersect(const Circle& c1, const Circle& c2) {
    double dist = sqrt(pow(c2.x - c1.x, 2) + pow(c2.y - c1.y, 2));
    return (dist <= c1.radius + c2.radius);
}

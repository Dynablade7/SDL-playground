#include "MathFunctions.h"

#include <cmath>

#define PI 3.14159265
#define radianConstant PI / 180 // To convert degrees to radians
#define degreeConstant 180 / PI // To convert radians to degrees

double math_calculateDist(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

double math_cos(double angle, double c) {
    return c * cos(angle * radianConstant);
}

double math_sin(double angle, double c) {
    return c * sin(angle * radianConstant);
}

double math_atan2(double y, double x) {
    return atan2(y, x) * degreeConstant;
}

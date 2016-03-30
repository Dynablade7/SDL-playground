#ifndef CIRCLE_H
#define CIRCLE_H

/**
 * A simple datatype representing a circle.
 */
class Circle {
    public:
        /**
         * Constructor.
         * @param x - The x position of the circle's center
         * @param y - The y position of the circle's center
         * @param radius - The circle's radius.
         */
        Circle(double x, double y, int radius);
        double x, y;
        int radius;
};

/**
 * Returns true if circles c1 and c2 intersect, else returns false.
 */
bool circle_intersect(const Circle& c1, const Circle& c2);

#endif // CIRCLE_H

#ifndef VECTOR2D_H
#define VECTOR2D_H

/**
 * A simple 2D vector ADT with some basic operations available.
 * The vector can only contain doubles.
 */
class Vector2D {
    public:

        /**
         * Constructor.
         */
        Vector2D(double x, double y);

        /**
         * Returns the scalar product of this vector and
         * the one passed as argument.
         */
        double scalarProduct(const Vector2D& v2d);

        /**
         * Returns the orthogonal projection of this vector
         * on the one passed as argument.
         */
        Vector2D project(const Vector2D& v2d);

        /**
         * Returns the result of mirroring this vector in
         * the one passed as an argument.
         */
        Vector2D mirror(const Vector2D& v2d);

        double getX() const;
        double getY() const;
        double getLenght() const;

        Vector2D operator-(const Vector2D& v2d);
        Vector2D operator*(double t);

    private:
        double _x, _y;
};

#endif // VECTOR2D_H

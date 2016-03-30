#ifndef VECTOR2D_H
#define VECTOR2D_H


class vector2D {
    public:
        vector2D(double x, double y);
        vector2D(double x1, double y1, double x2, double y2);
        double x, y;
};

double v2d_scalarProduct(vector2D& v1, vector2D& v2);

double v2d_scalarProduct(vector2D v, double x, double y);

vector2D v2d_orthProj(vector2D& v1, vector2D& v2);

#endif // VECTOR2D_H

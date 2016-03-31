#ifndef MATHFUNCTIONS_H_INCLUDED
#define MATHFUNCTIONS_H_INCLUDED

/*
    -----------------------------------------------------------------------
    This file will be used for mathematical functions that might
    come in handy in certain situations. This includes trigonometrical
    calculations, distance calculations, etc.

    The motivation for keeping these functions separately is to avoid bloaty
    calculations such as conversion from radians to degrees in the rest of the
    code, I prefer keeping it all in one place.

    More functions will be added when they are needed.
    -----------------------------------------------------------------------
*/

/**
 * Calculates the Pythagorean distance between the points (x1, y1) and
 * (x2, y2).
 */
double math_calculateDist(double x1, double y1, double x2 = 0, double y2 = 0);

/**
 * @param angle - The angle in degrees.
 * @param c - The constant by which the result is multiplied. Default 1.
 * @return cos(angle) * c
 */
double math_cos(double angle, double c = 1);

/**
 * @param angle - The angle in degrees.
 * @param c - The constant by which the result is multiplied. Default 1.
 * @return sin(angle) * c
 */
double math_sin(double angle, double c = 1);

/**
 * Returns the angle (in degrees) of the right triangle consisting
 * of oposite y and adjecent x. This function DOES take which quadrant
 * the triangle is in in consideration.
 * @param y - The oposite of the angle.
 * @param x - The adjecent of the angle.
 * @return atan2(y, x)
 */
double math_atan2(double y, double x);

#endif // MATHFUNCTIONS_H_INCLUDED

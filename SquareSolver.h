#include <cmath>

const double EPS = 1e-7;

enum
{
    SQ_INF_ROOTS = 100500
};

bool isZero(double a) 
{
    return std::abs(a) < EPS;
}

//-------------------------------------------------------------------------
//  Solves a square equation ax^2 + bx + c = 0
//  @param [in]     a   a-coefficient
//  @param [in]     b   b-coefficient
//  @param [in]     c   c-coefficient
//  @param [out]    x1  pointer to the first root
//  @param [out]    x2  pointer to the second root
//
//  @return Number of roots
//
//  @note In case of infinite amount of roots returns SQ_INF_ROOTS and *x1 and x2 are left unchanged
//  If the equation has 0 roots, values of *x1 and *x2 are left unchanged
//  Similarly, if the equation has 1 root, value of *x2 is unchanged
//-------------------------------------------------------------------------
int solveSquareEquation(double a, double b, double c, double *x1, double *x2)
{
    if (isZero(a)) {
        if (isZero(b)) {
            if (isZero(c)) {
                return SQ_INF_ROOTS;
            } else {
                return 0;
            }
        } else { //if (b != 0)
            *x1 = -c / b;
            return 1;
        }
    } else { //if (a != 0)
        double D = b*b - 4*a*c;
        if (D < -EPS) {
            return 0;
        } else if (isZero(D)) {
            *x1 = *x2 = -b / (2*a);
            return 1;
        } else { // if (D > 0)
            *x1 = (-b + sqrt(D)) / (2 * a);
            *x2 = (-b - sqrt(D)) / (2 * a);
            return 2;
        }
    }
}

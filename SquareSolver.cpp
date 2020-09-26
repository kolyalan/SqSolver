#include <cmath>
#include <cassert>

#include "SquareSolver.hpp"

bool isZero(double a) 
{
    assert(std::isfinite(a));
    return std::abs(a) < EPS;
}

int solveSquareEquation(double a, double b, double c, double *x1, double *x2)
{
    assert(std::isfinite(a));
    assert(std::isfinite(b));
    assert(std::isfinite(c));
    
    assert(x1 != nullptr);
    assert(x2 != nullptr);

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
        if (!std::isfinite(D)) {
            return 0;
        }
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

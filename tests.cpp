#include "SquareSolver.h"
#include <functional>
#include <iostream>

#define __ABC(a, b, c) "a = " << (a) << ", b = " << (b) << ", c = " << (c) << "."
#define __PAIR(x, y) "(" << x << ", " << y << ")" 

bool equal(double a, double b) {
    return std::abs(a - b) < EPS;
}

bool pair_match(int n, double a, double b, double x, double y)
{
    if (n == 0) return 1;
    if (n == 1) return a == x;
    if (n == 2) return (equal(a, x) && equal(b, y)) || (equal(a, y) && equal(b, x));
    if (n == SQ_INF_ROOTS) return 1;
    return 0;
}

void test(std::function<int(double, double, double, double*, double*)> f,  
        double a, double b, double c, int expNRoots, double exp_x1, double exp_x2) 
{
    double x1 = 0, x2 = 0;
    int nRoots = solveSquareEquation(a, b, c, &x1, &x2);
    if (nRoots != expNRoots) {
        std::cerr << "[FAILED] " << __ABC(a, b, c) <<
                " return value = " << nRoots << ", expected " << expNRoots << std::endl;
        return;
    }
    if (!pair_match(nRoots, x1, x2, exp_x1, exp_x2)) {
        std::cerr << "[FAILED] " << __ABC(a, b, c) <<
            " (x1, x2) = " << __PAIR(x1, x2) << ", expected " << __PAIR(exp_x1, exp_x2) << std::endl;
        return;
    }
    std::cerr << "[PASSED]" << std::endl;
}

int main()
{
    test(solveSquareEquation, 0, 1,  2,     1, -2,      0);
    test(solveSquareEquation, 7, 3, -10,    2,  1,  -10.0/7);
    test(solveSquareEquation, 0, 0,  0,     SQ_INF_ROOTS, 0, 0);
    test(solveSquareEquation, 0, 0,  2,     0, 0, 0);
    test(solveSquareEquation, 5, 5,  5,     0, 0, 0);
    test(solveSquareEquation, -10, 5,  5,   2, -0.5, 1);
    test(solveSquareEquation, -10, 5, -0.625, 1, 0.25,      0);
    
}

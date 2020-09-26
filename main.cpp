#include <iostream>
#include <cmath>
#include "SquareSolver.hpp"

int main()
{
    double a, b, c;
    std::cout << "Please, enter the coefficients of the square equation" << std::endl;
    std::cout << "a = " << std::flush;
    std::cin >> a;
    std::cout << "b = " << std::flush;
    std::cin >> b;
    std::cout << "c = " << std::flush;
    std::cin >> c;
    
    double x1 = NAN, x2 = NAN;
    int nRoots = solveSquareEquation(a, b, c, &x1, &x2);

    if (nRoots == 0) {
        std::cout << "The equation has no roots" << std::endl;
    } else if (nRoots == 1) {
        std::cout << "x = " << x1 << std::endl;
    } else if (nRoots == 2) {
        std::cout << "x1 = " << x1 << ", x2 = " << x2 << std::endl;
    } else if (nRoots == SQ_INF_ROOTS) {
        std::cout << "The equation has infinite amount of roots" << std::endl;
    } else {
        std::cerr << "main(): ERROR: nRoots = " << nRoots << std::endl;
        return 1;
    }
    return 0;
}

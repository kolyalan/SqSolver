#pragma once
const double EPS = 1e-6;

enum
{
    SQ_INF_ROOTS = 100500
};

/////////////////////////////////////////////////////////////////////////
///  Checks whether double value a is zero
///  @param [in]     a double value to check
///
///  @return true if a is close enough to 0
/////////////////////////////////////////////////////////////////////////
bool isZero(double a);

/////////////////////////////////////////////////////////////////////////
/// Solves a square equation ax^2 + bx + c = 0
/// @param [in]     a   a-coefficient
/// @param [in]     b   b-coefficient
/// @param [in]     c   c-coefficient
/// @param [out]    x1  pointer to the first root
/// @param [out]    x2  pointer to the second root
///
/// @return Number of roots
///
/// @note In case of infinite amount of roots returns SQ_INF_ROOTS and *x1 and x2 are left unchanged
/// If the equation has 0 roots, values of *x1 and *x2 are left unchanged
/// Similarly, if the equation has 1 root, value of *x2 is unchanged
/////////////////////////////////////////////////////////////////////////
int solveSquareEquation(double a, double b, double c, double *x1, double *x2);

#include "Quadratic_Function.h"

Quadratic_Function::Quadratic_Function(double quad_coef, double linear_coef, double constant):
    a(quad_coef), b(linear_coef), c(constant){}

double Quadratic_Function::operator()(double x)
{
    double res = a*x*x + b*x + c;
    return res;
}

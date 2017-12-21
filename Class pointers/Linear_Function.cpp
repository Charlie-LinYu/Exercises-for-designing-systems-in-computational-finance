#include "Linear_Function.h"

Linear_Function::Linear_Function(double coef, double constant):a(coef), b(constant){}

double Linear_Function::operator()(double x)
{
    return (a*x+b);
}

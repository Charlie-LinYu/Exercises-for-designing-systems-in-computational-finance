#ifndef QUADRATIC_FUNCTION_H_INCLUDED
#define QUADRATIC_FUNCTION_H_INCLUDED
#include "Function.h"

class Quadratic_Function: public Function
{
private:
    //a is the quadratic coefficient, b is the linear coefficient, c is the intercept term
    double a, b, c;
public:
    Quadratic_Function(double quad_coef, double linear_coef, double constant);  //constructor
    double operator() (double x);  //get x and return the result of the quadratic function
};


#endif // QUADRATIC_FUNCTION_H_INCLUDED

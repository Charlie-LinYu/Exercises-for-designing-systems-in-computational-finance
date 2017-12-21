#ifndef LINEAR_FUNCTION_H_INCLUDED
#define LINEAR_FUNCTION_H_INCLUDED
#include "Function.h"

class Linear_Function: public Function
{
private:
    double a, b;    //a is the linear coefficient, b is the intercept term
public:
    Linear_Function(double coef, double constant);    //constructor
    double operator() (double x);                     //get x and return the result of the linear function
};

#endif // LINEAR_FUNCTION_H_INCLUDED

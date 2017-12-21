#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED

//this is an abstract class
class Function
{
public:
    virtual double operator()(double x)=0;

};

#endif // FUNCTION_H_INCLUDED

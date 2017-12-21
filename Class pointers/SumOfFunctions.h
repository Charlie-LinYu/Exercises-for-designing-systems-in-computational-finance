#ifndef SUMOFFUNCTIONS_H_INCLUDED
#define SUMOFFUNCTIONS_H_INCLUDED
#include "Function.h"
#include <vector>

class SumOfFunctions: public Function
{
private:
    std::vector<Function*> ele_functions;                     //use vector to store pointers to function class
public:
    SumOfFunctions(Function* ptr);                            //constructor for a single pointer
    SumOfFunctions(const std::vector<Function*>& ptrs);       //constructor for a vector of pointers
    SumOfFunctions(const SumOfFunctions& twins);              //copy constructor
    void add_functions(Function* ptr);                        //add a new pointer
    void add_functions(const std::vector<Function*>& ptrs);   //add a vector of new pointers
    void initialize(Function* ptr);                           //initialize with a new pointer
    void initialize(const std::vector<Function*>& ptrs);      //initialize with a new vector of pointers
    double operator()(double x);                              //take x and return sum of f(x)
};

#endif // SUMOFFUNCTIONS_H_INCLUDED

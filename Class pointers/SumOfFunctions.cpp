#include "SumOfFunctions.h"
#include <algorithm>

//constructor with a pointer
SumOfFunctions::SumOfFunctions(Function* ptr)
{
    ele_functions.clear();
    ele_functions.push_back(ptr);
}

//constructor reloading with a vector of pointers
SumOfFunctions::SumOfFunctions(const std::vector<Function*>& ptrs)
{
    ele_functions.clear();
    ele_functions.resize(ptrs.size());
    std::copy(ptrs.begin(),ptrs.end(),ele_functions.begin());
}

//copy constructor
SumOfFunctions::SumOfFunctions(const SumOfFunctions& twins)
{
    ele_functions.clear();
    ele_functions.resize(twins.ele_functions.size());
    std::copy(twins.ele_functions.begin(),twins.ele_functions.end(),ele_functions.begin());
}

//add a new pointer
void SumOfFunctions::add_functions(Function* ptr)
{
    ele_functions.push_back(ptr);
}

//(reloading) add a vector of new pointers
void SumOfFunctions::add_functions(const std::vector<Function*>& ptrs)
{
    for(std::vector<Function*>::size_type i=0;i<ptrs.size();i++)
    {
        ele_functions.push_back(ptrs[i]);
    }
}

//initialize with a new pointer
void SumOfFunctions::initialize(Function* ptr)
{
    ele_functions.clear();
    ele_functions.push_back(ptr);
}

//(reloading) initialize with a vector of new pointers
void SumOfFunctions::initialize(const std::vector<Function*>& ptrs)
{
    ele_functions.clear();
    ele_functions.resize(ptrs.size());
    std::copy(ptrs.begin(),ptrs.end(),ele_functions.begin());
}

//calculate the sum of f(x)
double SumOfFunctions::operator()(double x)
{
    double sum = 0;
    for(std::vector<Function*>::size_type i=0;i<ele_functions.size();i++)
    {
        sum = sum + (*ele_functions[i])(x);
    }
    return sum;
}

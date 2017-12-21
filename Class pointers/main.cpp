#include <iostream>
#include <vector>
#include "Function.h"
#include "Linear_Function.h"
#include "Quadratic_Function.h"
#include "SumOfFunctions.h"
#include "Difference.h"

using namespace std;

//Homework 4 by Yu Lin; GTid:903327185
int main()
{
    //the codes below are for test only
    vector<Function*>ptrs;
    Linear_Function f1(1,0);        //f1(x)=x
    Linear_Function f2(2,0);        //f2(x)=2x
    Quadratic_Function f3(1,0,0);   //f3(x)=x^2
    Linear_Function f4(5,0);        //f4(x)=5x
    ptrs.push_back(&f1);
    ptrs.push_back(&f2);
    ptrs.push_back(&f3);
    SumOfFunctions sum1(ptrs);      //sum1(x)=f1(x)+f2(x)+f3(x)
    SumOfFunctions sum2(sum1);      //sum2(x)=sum1(x)
    sum2.add_functions(&f4);        //sum2(x)=f1(x)+f2(x)+f3(x)+f4(4)
    sum1.add_functions(ptrs);       //sum1(x)=f1(x)+f2(x)+f3(x)+f1(x)+f2(x)+f3(x)

    double res = Difference<Function,Function>(sum1,f3,10);

    cout<<res<<endl;
    cout<<sum1(10)<<endl<<f3(10)<<endl;

    return 0;
}

#ifndef DIFFERENCE_H_INCLUDED
#define DIFFERENCE_H_INCLUDED

template<class F1, class F2>
double Difference(F1& f1, F2& f2, double x)
{
    return f1(x) - f2(x);
}


#endif // DIFFERENCE_H_INCLUDED

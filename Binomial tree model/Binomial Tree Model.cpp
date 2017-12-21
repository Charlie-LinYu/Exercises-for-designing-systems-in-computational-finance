#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

//t is the length of one period and it is measure by year
double PutPrice(double s0, double k, double r, double sigma, double n, double t);

double CallPrice(double s0, double k, double r, double sigma, double n, double t);

int main()
{
    double s0 = 62, k = 60, r = 0.025, sigma = 0.2, t = 1.0/12.0;
    double n;
    double result1, result2;
    double u = exp(sigma * sqrt(t));
    double d = exp(-sigma * sqrt(t));
    double p = (exp(r * t) - d) / (u - d);
    while(cin>>n)
    {
        cout<<"Risk neutral probability: "<<p<<endl;
        result1 = CallPrice(s0,k,r,sigma,n,t);
        result2 = PutPrice(s0,k,r,sigma,n,t);
        cout<<"price of the call option:"<<result1<<endl;
        cout<<"price of the put option:"<<result2<<endl;
    }
    return 0;
}

double CallPrice(double s0, double k, double r, double sigma, double n, double t)
{
    vector< vector<double> > bitree;
    vector<double> layer;

    deque <vector<double> > bitree_opt;


//the u and d may have different forms
    double u = exp(sigma * sqrt(t));
    double d = exp(-sigma * sqrt(t));
    double p = (exp(r * t) - d) / (u - d);
    double exp_call;

    layer.push_back(s0);
    bitree.push_back(layer);
    for (int i = 1; i <= n; i++)
    {
        layer.clear();
        cout<<"Stock lattice "<<i<<": ";
        for (int j = 0; j <= i; j++)
        {
            if (j == 0)
            {
                layer.push_back(bitree[i-1][j] * u);
            }
            else
            {
                layer.push_back(bitree[i-1][j-1] * d);
            }
            cout<<layer[j]<<", ";
        }
        bitree.push_back(layer);
        cout<<endl;
    }

    for (int i = n; i >= 0; i--)
    {
        layer.clear();
        cout<<"Call option lattice "<<i<<": ";
        for (int j = 0; j <= i; j++)
        {
            if (i == n)
            {
                layer.push_back(max(0.0, bitree[n][j] - k));
            }
            else
            {
                exp_call = exp(-r * t) * (bitree_opt[0][j] * p + bitree_opt[0][j + 1] * (1-p));
                layer.push_back(exp_call);
                //American style
                //layer.push_back(max(exp_call, bitree[i][j] - k));
            }
            cout<<layer[j]<<", ";
        }
        bitree_opt.push_front(layer);
        cout<<endl;
    }
    return bitree_opt[0][0];
}

double PutPrice(double s0, double k, double r, double sigma, double n, double t)
{
    vector< vector<double> > bitree;
    vector<double> layer;

    deque <vector<double> > bitree_opt;

    double u = exp(sigma * sqrt(t));
    double d = exp(-sigma * sqrt(t));
    double p = (exp(r * t) - d) / (u - d);
    double exp_put;

    layer.push_back(s0);
    bitree.push_back(layer);
    for (int i = 1; i <= n; i++)
    {
        layer.clear();
        cout<<"Stock lattice "<<i<<": ";
        for (int j = 0; j <= i; j++)
        {
            if (j == 0)
            {
                layer.push_back(bitree[i-1][j] * u);
            }
            else
            {
                layer.push_back(bitree[i-1][j-1] * d);
            }
            cout<<layer[j]<<", ";
        }
        bitree.push_back(layer);
        cout<<endl;
    }

    for (int i = n; i >= 0; i--)
    {
        layer.clear();
        cout<<"Put option lattice "<<i<<": ";
        for (int j = 0; j <= i; j++)
        {
            if (i == n)
            {
                layer.push_back(max(0.0, k - bitree[n][j]));
            }
            else
            {
                exp_put = exp(-r * t) * (bitree_opt[0][j] * p + bitree_opt[0][j + 1] * (1-p));
                layer.push_back(exp_put);
                //American style
                //layer.push_back(max(exp_put, k - bitree[i][j]));
            }
            cout<<layer[j]<<", ";
        }
        bitree_opt.push_front(layer);
        cout<<endl;
    }
    return bitree_opt[0][0];
}

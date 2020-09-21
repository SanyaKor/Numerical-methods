
#include <stdio.h>
#include "vector"
#include "math.h"
#include <iostream>

using namespace  std;

class func{
public:
    int N,s;
    int dim;
    double *fx;
    double *fy;
    double thck;

    func(int NN,int size,double thickness);
    ~func();

    double lagrange(vector<double> fy,vector<double>  fx, double  x);
    double newtone(vector<double> arrX,vector<double> arrY, double x);

    void maker(double (*f)(double),int d,bool k);
};

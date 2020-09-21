#include <iostream>
#include "vector"
#include "math.h"

using namespace std;

class spline {
public:
    int N;
    vector<double> x;
    vector<double> y;

    vector<double> h;
    vector<double> l;

    vector<double> delta;
    vector<double> lambda;

    vector<double> b;
    vector<double> c;
    vector<double> d;


    spline(int n);
    void ini();
    void h_l_solver();
    void interpolation();
    void func_x(double xx);
    void print_equation();
    void xy_print();
    ~spline();
};

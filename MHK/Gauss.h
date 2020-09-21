#include "vector"
#include <iostream>
using namespace  std;
class Gauss {

public:
    int N;
    int M;

    vector<double> x;

    vector<vector<double>> G_Mx;

    Gauss(int sn,int sm,vector<vector<double>> MX);
    void G_tuda();
    void G_obratno();
    void print_mx();
    void eq_printer(vector<double> x);
    ~Gauss();
};

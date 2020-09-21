#include "vector"
#include "iostream"
using  namespace  std;

class matrix {
public:
    int n;// колличество точек
    int m; // степень многочлена
    vector <double>s;// вектор с суммами
    vector<vector<double>> MX;// матрица

    vector<double> x;
    vector<double> y;

    matrix(int n,int m);
    void m_ini();
    void sum();
    void sum_yx();
    void matrix_solver();
    void matrix_printer();
    ~matrix();
};



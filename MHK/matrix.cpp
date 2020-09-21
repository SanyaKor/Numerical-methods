
#include "matrix.h"
#include "math.h"

matrix::matrix(int nn, int mm) {
    n = nn;
    m = mm;

    MX.resize(m+1);
    for (int i = 0; i < m+1; i++)
        MX[i].resize(m+2);
    m_ini();
}

void matrix::m_ini() {
 /*   x.push_back(-3);
    x.push_back(-1);
    x.push_back(0);
    x.push_back(1);
    x.push_back(3);

    y.push_back(-4);
    y.push_back(-0.8);
    y.push_back(1.6);
    y.push_back(2.3);
    y.push_back(1.5);
*/
    for(int i=1;i<6;i++){
        x.push_back(i);
    }
    y.push_back(5.3);
    y.push_back(6.3);
    y.push_back(4.8);
    y.push_back(3.8);
    y.push_back(3.3);

    matrix_solver();

}
void matrix::sum() {
    double ssum;
    for(int j=1;j<2*m+1;j++) {
        ssum=0;
        for (int i = 0; i < n; i++) {
            ssum += pow(x[i], j);
        }

        s.push_back(ssum);
    }
}

void matrix::sum_yx() {
    double ssum;
    for(int j=0;j<=m;j++) {
        ssum=0;
        for (int i = 0; i < n; i++) {
            ssum += y[i]*pow(x[i], j);
        }

        s.push_back(ssum);
    }

}

void matrix::matrix_solver() {
    sum();
    sum_yx();

    MX[0][0] = n;

    for (int i = 0; i < m+1; i++) {
        for (int j = 0 ; j < m+2; j++) {
            if(i+j>0)
                MX[i][j] = s[i+j-1];
            }
    }

    for (int i = 0; i < m+1; i++) {
        MX[i][m+1] = s[2*m+i];
    }

 }

void matrix::matrix_printer() {
    for (int i = 0; i < m+1; i++) {
        for (int j = 0; j < m+2; j++) {
                cout  << MX[i][j] << "  ";
        }
        cout << endl;
    }
}

matrix::~matrix() {
    s.clear();
    x.clear();
    y.clear();
    MX.clear();
}
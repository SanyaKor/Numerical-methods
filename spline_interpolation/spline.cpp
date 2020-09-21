
#include "spline.h"

spline::spline(int n) {
    N = n+1;

    l.resize(N);
    h.resize(N);
    delta.resize(N);
    lambda.resize(N);
    b.resize(N);
    c.resize(N);
    d.resize(N);

    N-=1;

    ini();


}

void spline::xy_print() {
    for(int i=0;i<=N;i++){
        cout << x[i] << "  ";
        cout << y[i] << endl;
    }
}

void spline::ini() {

    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    x.push_back(4);
    x.push_back(5);

    y.push_back(5);
    y.push_back(3);
    y.push_back(2.5);
    y.push_back(2);
    y.push_back(0);

    h_l_solver();
    interpolation();

}
void spline::print_equation(){
    for(int i=1;i<=N;i++){
        cout << y[i]  << " + " << b[i] << "*x"
        << " + " << c[i]  << "*x^2" << " + " << d[i]  << "*x^3 = 0"<< endl;
        cout << endl;
    }
}

void spline::h_l_solver() {
    for(int i=1;i<=N;i++){
        h[i] = x[i] - x[i-1];
        l[i] = (y[i] - y[i-1])/h[i];
    }
}

void spline::func_x(double xx){
    double F=0;
    cout << endl;
    for(int k=1;k<=N;k++){
        F = y[k] + b[k]*(xx) + c[k]*pow(xx, 2) + d[k]*pow(xx, 3);
        cout <<" m_" << k << "(" << xx << ")" << " = " << F << "   " << endl;
    }

}

void spline::interpolation() {

    delta[1] = - h[2]/(2*(h[1]+h[2]));
    lambda[1] = 1.5*(l[2] - l[1])/(h[1]+h[2]);

    c[0] = 0;
    c[N] = 0;

    for(int i=3;i<=N;i++){
        delta[i-1] = -h[i] / (2*h[i-1] + 2*h[i] + h[i-1]*delta[i-2]);
        lambda[i-1] = (3*l[i] - 3*l[i-1] - h[i-1]*lambda[i-2]) /
                (2*h[i-1] + 2*h[i] + h[i-1]*delta[i-2]);
    }

    for(int k=N; k>=2; k--){
        c[k-1] = delta[k-1]*c[k] + lambda[k-1];
    }
    for(int k=1; k<=N; k++){
        d[k] = (c[k] - c[k-1])/(3*h[k]);
        b[k] = l[k] + (2*c[k]*h[k] + h[k]*c[k-1])/3;
    }
    print_equation();

}

spline::~spline() {
    delta.clear();
    lambda.clear();
}

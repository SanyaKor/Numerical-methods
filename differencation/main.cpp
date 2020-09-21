#include <iostream>
#include <math.h>
#include "vector"
using  namespace  std;

double left_diff(vector<double> y,double h,int i){
    double yi = (y[i]-y[i-1])/h;
    return yi;
}


double right_diff(vector<double> y,double h,int i){
    double yi = (y[i+1]-y[i])/h;
    return yi;
}


double central_diff(vector<double> y,double h,int i){
    double yi = (y[i+1]-y[i-1])/(2*h);
    return yi;
}

double second_diff(vector<double> y,double h,int i){
    double yi = (y[i+1]-2*y[i]+y[i-1])/(h*h);
    return yi;
}



int main() {
    double h = 0.5;
    vector<double> y;


    y.push_back(0.40547);
    y.push_back(0.69315);
    y.push_back(0.91629);

    /*
    y.push_back(0);
    y.push_back(0.5);
    y.push_back(0.86603);
     */
    double a1 = left_diff(y,h,1) ;


    double b1 = right_diff(y,h,1) ;


    double c1 = central_diff(y,h,1) ;

    double d1 = second_diff(y,h,1);
    //cout << second_diff(a1,a2,h) << endl;

    //cout << second_diff(b1,b2,h) << endl;

    //cout << second_diff(c1,c2,h);
    cout << "Левые разности:" << endl;
    cout << a1 << endl;

    cout << "Правые разности:" << endl;
    cout << b1 << endl;

    cout << "Центральные разности:" << endl;
    cout << c1 << endl;

    cout << "Вторая производная"  << endl;
    cout << d1 << endl;

    return 0;
}

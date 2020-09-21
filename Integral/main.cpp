#include <iostream>
#include "math.h"
using namespace  std;

double my_func(double x)
{
    //double y = x/((3*x+4)*(3*x+4));
    double y = 1/log(x);
    return y;
}

double left_squares(double h,int a,int b)
{
    double sum=0;
    for(double i=a;i<b;i+=h){
        sum+=my_func(i);
    }
    return h*sum;
}

double right_squares(double h,int a,int b)
{
    double sum=0;
    for(double i=a+h;i<b+h;i+=h){
        sum+=my_func(i);
    }
    return h*sum;
}

double central_squares(double h,int a,int b)
{
    double sum=0;
    for(double i=a+h/2;i<b;i+=h){
        sum+=my_func(i);
    }
    return h*sum;
}

double Simpson(double h,double a,double b){
    double sum = 0;
    for(double i=a+2*h;i<=b-h;i+=2*h){
        sum+=2*my_func(i);
    }
    for(double i=a+h;i<=b-h;i+=2*h){
        sum+=4*my_func(i);
    }
    sum+=(my_func(a)+my_func(b));
    return h*sum/3;
}


double trapezoid(double h,int a,int b){
    double sum = 0;
    for(double i=a+h;i<=b-h;i+=h){
        sum+=my_func(i);
    }
    sum+=(my_func(a)+my_func(b))/2;

    return h*sum;
}



int main()
{
    double h=0.6;
    double a=2;
    double b=5;
    cout << endl;
    cout << "Метод левых прямоугольников: " << left_squares(h,a,b) << endl;
    cout << "Метод правых прямоугольников: " << right_squares(h,a,b) << endl;
    cout << "Метод центральных прямоугольников: " << central_squares(h,a,b) << endl;

    cout << "Метод Трапеций: " << trapezoid(h,a,b) << endl;
    cout << "Метод Симпсона: " << Simpson(h,a,b) << endl;
    return 0;
}

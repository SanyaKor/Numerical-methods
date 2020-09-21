//
//  main.cpp
//  Taylor
//
//  Created by SHuriG on 03.09.2020.
//  Copyright © 2020 SHuriG. All rights reserved.
//

#include <iostream>
#include <math.h>

#define LN10 2.3025851;

using namespace std;

double custom_sin(double x, double eps)
{
    double current = x;
    double sum = x;
    int i = 1;
    while(fabs(current) > eps)
    {
        i+=2;
        
        current = current*x*x/((i)*(i-1));
        current=current*(-1);
        sum = sum + current;
        
    }
    return sum;
}

double custom_exp(double x, double eps)
{
    double current = x;
    double sum = 1+x;
    int i = 1;
    while(fabs(current) > eps)
    {
        i+=1;
        
        current = current*x/(i);
        sum = sum + current;
    }
    return sum;
}

double custom_cos(double x,double eps){
    double current = 1;
    double sum = 1;
    
    int i = 2;
    while(fabs(current) > eps ){
        current = (-1)*current*x*x/((i)*(i-1));
        sum = sum + current;
        i+=2;
    }
    
    return sum;
}

double custom_log(double x,double eps){
    
    double ln10_counter = 0;
    if(x<0){
        cout << "Число отрицательное" << endl;
        return 0;
    }
    
    int i = 2;
    while(x>1){
        x = x/10;
        ln10_counter++;
    }
    x=x-1;
    double current = x;
    double sum = x;
    while(fabs(current) > eps ){
        current = (-1)*(i-1)*current*x/i;
        sum = sum + current;
        //cout << sum << endl;
        i+=1;
    }
    if(ln10_counter!=0)
    {
        sum = sum + ln10_counter*LN10;
        return sum/LN10;
    }
    else
        return sum/LN10;
}

double custom_ln(double x,double eps){
    double ln10_counter = 0;
    int i = 2;
    if(x<0){
        cout << "Число отрицательное" << endl;
        return 0;
    }
    while(x>1){
        x = x/10;
        
        ln10_counter++;
    }
    x=x-1;
    int kolvo=0;
    double current = x;
    double sum = x;
    while(fabs(current) > eps ){
        current = (-1)*(i-1)*current*x/i;
        sum = sum + current;
        kolvo++;
        i+=1;
    }
    cout << "колличество членов ряда:" << kolvo << endl;
    
    if(ln10_counter!=0)
    {
        sum = sum + ln10_counter*LN10;
        return sum;
    }
    else
        return sum;
}

double custom_logic(double a,double b,double eps){
    double sum=0;
    a = custom_ln(a, eps);
    b = custom_ln(b, eps);
    sum = b/a;
    return sum;
}

int main(int argc, const char * argv[]) {
    int menu = 1;
    double ln10 = 2.3025851;
    double eps=0.00001, x=0.5,res;
    while(menu!=0){
        cout << "x = " << x << "  eps = " << eps << endl;
        cout << "1)Cos(x)" << endl;
        cout << "2)Loga(b)" << endl;
        cout << "3)Ln(x)" << endl;
        cout << "4)Sin(x)" << endl;
        cout << "5)Exp(x)" << endl;
        cout << "6)Изменить значение eps" << endl;
        cout << "7)Изменить значение x" << endl;
        cout << "8)Выход" << endl;
        
        cin >> menu;
    switch (menu)
        {
        case 1:
            res = custom_cos(x, eps);
            cout << "Ряд Тейлора для cos(x) расчитанный с точностью " << eps << ": " << res << endl;
            cout << "Значение встроенной функции: " << cos(x) << endl;
            break;
        case 2:
            double a,b;
            cout << "Введите a: " << endl;
            cin >> a;
            cout << "Введите b: " << endl;
            cin >> b;
            res = custom_logic(a,b, eps);
            cout << "Ряд Тейлора для loga(b) расчитанный с точностью " << eps << ": " << res << endl;
            cout << "Значение встроенной функции: " << log(b)/log(a) << endl;
            cout << endl;
                
            break;
        case 3:
            res = custom_ln(x, eps);
            cout << "Ряд Тейлора для ln(x) расчитанный с точностью " << eps << ": " << res << endl;
            cout << "Значение встроенной функции: " << log(x) << endl;
            cout << endl;
                
            break;
        case 4:
            res = custom_sin(x, eps);
            cout << "Ряд Тейлора для sin(x) расчитанный с точностью " << eps << ": " << res << endl;
            cout << "Значение встроенной функции: " << sin(x) << endl;
            cout << endl;
                
            break;
        case 5:
            res = custom_exp(x, eps);
            cout << "Ряд Тейлора для exp(x) расчитанный с точностью " << eps << ": " << res << endl;
            cout << "Значение встроенной функции: " << exp(x) << endl;
            cout << endl;
            break;
        case 6:
            cout << "Введите значение eps:" << endl;
            cin >> eps;
            break;
        case 7:
            cout << "Введите значение x:" << endl;
            cin >> x;
            break;
        case 8:
            menu=0;
            break;
                
        }
    }
    return 0;
}

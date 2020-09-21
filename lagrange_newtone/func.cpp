//
//  lagrange.cpp
//  Terka
//
//  Created by SHuriG on 11.09.2020.
//  Copyright © 2020 SHuriG. All rights reserved.
//

#include "func.h"

func::func(int NN,int size,double thickness){
    N = NN;
    fx = new double[N];
    fy = new double[N];
    s = size;
    thck = thickness;
    //maker(s,thck);
}

double  func::lagrange(vector<double> fy,vector<double>  fx, double  x) {
    double ch = 1, zn = 1,res1 = 0;
    int i = 0, j = 0;
    for (j = 0; j < dim; j++) {
        ch = 1, zn = 1;
        for (i = 0; i < dim; i++) {
            if (i != j) {
                ch *= (x - fx.at(i));
                zn *= (fx.at(j) - fx.at(i));
            }
        }
        ch = ch * fy.at(j);

        res1+=ch/zn;
    }

    return res1;
}
double func::newtone(vector<double> arrX,vector<double> arrY,double x){
    double res = arrY.at(0);
    double current = 1;
    vector<double> arrY0;


    for(int j=0;j<dim;j++){

        for(int i=0;i<dim-j-1;i++){
            arrY.at(i) = (arrY.at(i+1)-arrY.at(i))/(arrX.at(i+j+1)-arrX.at(i));
            if(i==0)
                arrY0.push_back(arrY.at(i));
        }

    }
    for (int i=0;i<dim-1;i++){
        current = current*(x-arrX.at(i));
        res+=arrY0.at(i)*current;
    }


    return res;
}



void func::maker(double (*f)(double),int d,bool k){
    dim = d;
    double anchor = -N*thck/2;
    vector<double> ax;
    vector<double> ay;
    double g;
    for (int i = 0; i < dim; i++) {
        g = i*3.14/6;
        ax.push_back(g);
    }
    cout << "x       y" << endl;
    for (int i = 0; i < dim; i++) {
        g = f(ax[i]);
        ay.push_back(g);

        cout << ax[i] << " " << ay[i] << endl;
    }
    if(k)
    {
        for (int i = 0; i < N; i++) {
            fx[i] = (anchor + thck * i) * s;
            fy[i] = lagrange(ay, ax, fx[i] / s) * s;
        }
    }
    else
        {
            for (int i = 0; i < N; i++)
            {
                fx[i] = (anchor + thck * i) * s;
                double res = newtone(ax, ay, fx[i] / s) * s;
                fy[i] = res;
            }
        }
    /*for(int i=0;i<3;i++) {
        cout << "Лагранж  cosx в точке x = " << (ax[i+1]+ax[i])/2 << " : " << lagrange(ay, ax, (ax[i+1]+ax[i])/2) << endl;
        cout << "Ньютон cosx в точке x = " << (ax[i+1]+ax[i])/2 << " : "  << newtone(ax, ay, (ax[i+1]+ax[i])/2) << endl;
        cout << "cosx в точке x = " << (ax[i+1]+ax[i])/2 << " : " << cos((ax[i+1]+ax[i])/2) << endl;
        cout << endl;
    }*/

}

func::~func(){
    delete fx;
    delete fy;
}

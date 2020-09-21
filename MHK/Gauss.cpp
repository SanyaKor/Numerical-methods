//
// Created by SHuriG on 19.09.2020.
//

#include "Gauss.h"

Gauss::Gauss(int sn, int sm, vector<vector<double>> MX) {
    N = sn;
    M = sm;

    G_Mx.resize(N);
    for (int i = 0; i < N; i++)
        G_Mx[i].resize(M);

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            G_Mx[i][j] = MX[i][j];
        }
    }

    G_tuda();
}


void Gauss::eq_printer(vector<double> x){
    for (int i=0; i<x.size(); i++) {
        if(i==0)
            cout << x[i] << " + " ;
        else if(i<x.size()-1)
            cout << x[i] << "*x^" << i << " + " ;
        else
            cout << x[i] << "*x^" << x.size()-1 << " = 0" << endl;
    }
}

void Gauss::print_mx() {
    cout << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << G_Mx[i][j] << "      ";
        }
        cout << endl;
    }
}

void Gauss::G_tuda() {

    for(int k=0;k<N;k++)
    {
        for (int i=k+1; i<N; i++)
        {
            double temp = G_Mx[i][k]/G_Mx[k][k];
            for (int j=k+1; j<=N; j++)
                G_Mx[i][j] -= G_Mx[k][j]*temp;
            G_Mx[i][k] = 0;
        }
    }
    G_obratno();
}

void Gauss::G_obratno() {
    x.resize(N);

    for (int i = N-1; i >= 0; i--)
    {
        x[i] = G_Mx[i][N];
        for (int j=i+1; j<N; j++)
        {
            x[i] -= G_Mx[i][j]*x[j];
        }

        x[i] = x[i]/G_Mx[i][i];
    }
    eq_printer(x);
  }

Gauss::~Gauss() {
    G_Mx.clear();
    x.clear();
}

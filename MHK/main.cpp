#include "matrix.h"
#include "Gauss.h"
#include "plotter.h"
using namespace  std;

void ini(int n,int deg){
    plotter p(1000,500,0.1,100,100);
    deg+=1;
    for(int i=1;i<deg;i++) {
        matrix l(n, i);
        Gauss G(i+1, i+2, l.MX);
        p.n_mnogochlen(G.x);
        p.p_plotter(l.x,l.y);
    }

    p.init();

}

int main() {
    ini(5,3);
    return 0;
}


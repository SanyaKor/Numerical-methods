
#include "spline.h"
#include "plotter.h"
int main() {
    spline s(4);
    s.func_x(1.5);
    plotter p(1000,500,100,10);
    p.n_mnogochlen(s.y,s.b,s.c,s.d,s.x);
    p.init();
    return 0;
}

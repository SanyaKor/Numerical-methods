#include "plotter.h"
#include "math.h"
#include "func.h"
using namespace sf;
using namespace std;



int main() {
    plotter p(1000, 500, 0.1, 1000, 25);
    func f(1000,25,0.1);
    f.maker(cos, 4,0);
    p.current(cos);
    p.add(f.fx, f.fy);
    p.init();

    return 0;
}
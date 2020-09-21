#include <SFML/Graphics.hpp>
#include <iostream>
#include "vector"
#include "math.h"

using namespace  std;
using namespace sf;
class plotter {
public:
    int sx;
    int sy;
    int N;
    int size;
    int color=50;

    double thickness;
    double anchor;

    sf::RenderWindow *window;

    vector<VertexArray> list;
    vector<CircleShape> points;

    plotter(int sxx, int syy, double thck, int n, double s);

    ~plotter();

    void init();

    void p_plotter(vector<double> x,vector<double> y);

    void n_mnogochlen(vector<double> x);

    void add( vector<double> y);


};


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

    sf::RenderWindow *window;

    vector<VertexArray> list;

    plotter(int sxx, int syy, int n, double s);

    ~plotter();

    void init();


    void n_mnogochlen(vector<double> a,vector<double> b,vector<double> c,
                      vector<double> d,vector<double> x);
    void add(vector<double> y);

};


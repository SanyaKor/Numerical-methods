#include <SFML/Graphics.hpp>
#include <iostream>
#include "vector"


using namespace sf;
using namespace std;

class plotter {
public:
    int sx;
    int sy;
    int N;
    int size;
    int color;

    double thickness;
    double anchor;

    sf::RenderWindow *window;

    vector<VertexArray> list;

    plotter(int sxx, int syy, double thck, int n, double s);

    ~plotter();

    void init();

    void add(double *x, double *y);

    void current(double (*fu)(double));

    void addfun(double (*fun)(double), int x0, int x1);


    };
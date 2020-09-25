#include "plotter.h"

plotter::plotter(int sxx, int syy, int n, double s) {
    sx = sxx;
    sy = syy;
    N = n;
    size = s;
}


void plotter::init()
{
    window = new sf::RenderWindow(sf::VideoMode(sx, sy), "sfml");

    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window->close();
                this->~plotter();
                return;
            }

            window->clear(Color::White);
            for(int i=0;i<list.size();i++){
                window->draw(list[i]);
            }

            window->display();
        }
    }
}

void plotter::add(vector<double> y) {
    VertexArray curve(sf::LineStrip,y.size());
    color+=50;
    int color_change=0;
    for(int i =0;i<y.size();i++){
        curve[i] = sf::Vector2f(i, sy/2+y[i]);
        color_change++;
        if(color_change>=y.size()/4) {
            color_change = 0;
            color+=40;
        }
        Color Ccolor(1*color , 3*color, 2*color);
        curve[i].color = Ccolor;
    }

    list.push_back(curve);
}


void plotter::n_mnogochlen(vector<double> a,vector<double> b,vector<double> c,
                           vector<double> d,vector<double> x){
    double res=0;
    int k=1;
    vector<double> Y;
    double begin = x[0];
    double end = x[x.size()-1];
    double step = (end-begin)/sx;

    for(double i = begin;i<=end;i+=step) {
        for (k = 1; k <= x.size(); k++) {
            if (i >= x[k - 1] && i <= x[k]) {
                break;
            }
        }
        res = a[k] + b[k] *  (i - x[k])
              + c[k] * pow((i - x[k]), 2)
              + d[k] * pow((i - x[k]), 3);

        Y.push_back(-res*size);
    }




    add(Y);
}

plotter::~plotter(){
    delete window;
}


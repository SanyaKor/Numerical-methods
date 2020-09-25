#include "plotter.h"

plotter::plotter(int sxx, int syy, double thck, int n, double s) {
    sx = sxx;
    sy = syy;
    thickness = thck;
    N = n;
    size = s;
    anchor = -N*thickness/2;
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

void plotter::p_plotter(vector<double> x,vector<double> y) {
    CircleShape shape(2.5);
    shape.setFillColor(Color::Red);
    int x0=-1;
    int x1=1;
    double xlen = abs(x1-x0);

    for(int i=0;i<x.size();i++){
        shape.setPosition(sx/2+x[i],sy/2+(x0 + ((xlen / sx) * y[i])));
        points.push_back(shape);
    }
}



void plotter::add(vector<double> y) {
    VertexArray curve(sf::LineStrip,sx);
    color+=50;

    for(int i =0;i<sx;i++){
        curve[i] = sf::Vector2f(i, sy/2+y[i]);
        Color Ccolor(1*color , 3*color, 2*color);
        curve[i].color = Ccolor;
    }

    list.push_back(curve);
}



void plotter::n_mnogochlen(vector<double> x) {
    int x0=-50;
    int x1=50;
    double xlen = abs(x1-x0);
    vector<double> y(sx);
    for(int i=0;i<sx;i++){
        for(int j=0;j<x.size();j++){
            y[i]+= x[j]*pow((x0 + ((xlen / sx) * i)),j);
        }
    }

    add(y);
}

plotter::~plotter(){
    delete window;
}


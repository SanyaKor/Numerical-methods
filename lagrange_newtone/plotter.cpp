//
// Created by SHuriG on 12.09.2020.
//

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
    CircleShape shape(2.5);
    shape.setFillColor(Color::White);
    shape.setPosition(sx/2-1.25,sy/2-1.25);
    window = new sf::RenderWindow(sf::VideoMode(sx, sy), "sfml");

    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window->close();
                this->~plotter();
                return;
            }

            window->clear(Color::Black);
            for(int i=0;i<list.size();i++){
                window->draw(list[i]);
            }
            window->draw(shape);
            window->display();
        }
    }
}

void plotter::add(double *x, double *y) {
    VertexArray points(sf::LineStrip,N);
    color+=50;
    //cout << anchor << endl;
    for(int i =0;i<N;i++){
        points[i] = sf::Vector2f(sx/2+x[i],sy/2+y[i]);
        Color Ccolor(1*color , 3*color, 2*color);
        points[i].color = Ccolor;
    }
    list.push_back(points);
}

void plotter::current(double (*fu)(double)) {
    double *x,*y;
    x = new double[N];
    y = new double[N];
    for(int i=0;i<N;i++){
        x[i] = (i*thickness+anchor)*size;
        y[i] = fu(x[i]/size)*size;
    }
    add(x,y);
}


void plotter::addfun(double (*fun)(double), int x0, int x1) {
    long double xlen = abs(x1 - x0);
    sf::VertexArray curve(sf::LinesStrip, sx);

    for (int i = 0; i < sx; i++)
    {
        curve[i] = sf::Vector2f(i,-20*(fun(x0 + ((xlen / sx) * i)))+sy/2);
        //std::cout<<curve[i].position.y<<"   ";
        //std::cout<<curve[i].position.x<<endl;
    }
    list.push_back(curve);
}

plotter::~plotter(){
    delete window;
}

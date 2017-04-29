#ifndef GRAPHER_H
#define GRAPHER_H

#include <ctime>
#include <cstdlib>
#include <vector>
#include "Color.h"
#include "Shapes.h"
#include "SDL_Plotter.h"

class Graph{
public:
	Graph(SDL_Plotter *p, int n, Point origin, Point size);
    void drawAxis(Color c = COLOR::BLACK);
    void plot(int** (*f)(int**,int**,int));
    void test();
    void redraw();
    void clear();
    void setColor(Color);
private:
	int** (*func)(int**,int**,int);
    int n,
        maxTime,
        prevMax;
    Point origin,
          size;
    SDL_Plotter *plotter;
    Color c;
    vector<vector<Point> > points;
    vector<vector<int> > times;
};

#endif

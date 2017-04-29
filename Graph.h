#ifndef GRAPHER_H
#define GRAPHER_H

#include <cstdlib>
#include <vector>
#include <map>
#include "Color.h"
#include "Shapes.h"
#include "Font.h"
#include "SDL_Plotter.h"

typedef int**(*MatrixMultFunc)(int**,int**,int);

class Graph{
public:
	Graph(SDL_Plotter &p, Font &f, int n, Point origin, Point size);
    void drawAxis(Color c = COLOR::BLACK);
    void plot(MatrixMultFunc);
    void test();
    void redraw();
    void clear();
    void clear(MatrixMultFunc);
    void setColor(Color);
    void setN(int);
    void setNLoc(Point);
private:
	MatrixMultFunc func;
    int n,
        maxTime;
    Point origin,
          size,
          nloc;
    SDL_Plotter *plotter;
    Color c;
    Font *font;
    map<MatrixMultFunc,vector<Point> > points;
    map<MatrixMultFunc,vector<int> > times;
};

class DataPoint {
public:
    Point data;
    Point loc;
    DataPoint(Point, Point);

    void draw(SDL_Plotter&, Font, int);
};
#endif

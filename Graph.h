#ifndef GRAPHER_H
#define GRAPHER_H

#include <cstdlib>
#include <vector>
#include <map>
#include <chrono>
#include "Color.h"
#include "Shapes.h"
#include "Font.h"
#include "SDL_Plotter.h"

typedef int**(*MatrixMultFunc)(int**,int**,int);
typedef std::chrono::high_resolution_clock Clock;

class Graph{
public:
	Graph(SDL_Plotter &p, Font &f, int n, Point origin, Point size);
    void drawAxis();
    void plot(MatrixMultFunc f, Color color = COLOR::BLACK);
    void test();
    void erase(MatrixMultFunc f = NULL);
    void redraw();
    void clear();
    void clear(MatrixMultFunc);
    void setColor(Color);
    void setN(int);
    void setNLoc(Point);
private:
	MatrixMultFunc func;
    int n,
        maxTime,
        maxN;
    Point origin,
          size,
          nloc;
    SDL_Plotter *plotter;
    Color c;
    Color eraser;
    Font *font;
    map<MatrixMultFunc,Color>           colors;
    map<MatrixMultFunc,vector<Point> >  points;
    map<MatrixMultFunc,vector<int> >    times;
    map<MatrixMultFunc,vector<int> >    n_values;
};

class DataPoint {
public:
    Point data;
    Point loc;
    DataPoint(Point, Point);

    void draw(SDL_Plotter&, Font, int);
};
#endif

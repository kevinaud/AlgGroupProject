/**
* Authors: Kevin Aud|Jesse McNicoll|Connor Blandin|Jackson Swenson
* Assignment Title: Group Project
* Assignment Description: This header file contains the function definition for
*	the graphing class that handles all of the drawing to the screen
* Due Date: 5/1/2017
* Date Created: 4/28/2017
* Date Last Modified: 5/1/2017
*/


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
#include "polyReg.h"

typedef int**(*MatrixMultFunc)(int**,int**,int);
typedef std::chrono::high_resolution_clock Clock;

class Graph{
public:
	Graph(SDL_Plotter &p, Font &f, int n, Point origin, Point size);
    void drawAxis();
    bool plot(MatrixMultFunc f, Color color = COLOR::BLACK);
    void smooth();
    void test();
    void erase(MatrixMultFunc f = NULL);
    void redraw();
    void clear();
    void clear(MatrixMultFunc);
    void setColor(Color);
    void setN(int);
    void setNLoc(Point);
    void setSmoothness(int);
    void setSmoothLoc(Point);
private:
	MatrixMultFunc func;
    int n,
        degree,
        maxTime;
    string units;
    Point origin,
          size,
          nloc,
          sloc;
    SDL_Plotter *plotter;
    Color c;
    Color eraser;
    Font *font;
    map<MatrixMultFunc,Color>           colors;
    map<MatrixMultFunc,vector<Point> >  points;
    map<MatrixMultFunc,vector<int> >    times;
    map<MatrixMultFunc,vector<int> >    n_values;
    map<MatrixMultFunc,bool>            is_smooth;
};

class DataPoint {
public:
    Point data;
    Point loc;
    DataPoint(Point, Point);

    void draw(SDL_Plotter&, Font, int);
};
#endif

#include <algorithm>
#include <cmath>
#include "SDL_Plotter.h"

#ifndef SHAPES_H_INCLUDED
#define SHAPES_H_INCLUDED

class Line {
public:
    int x1, y1;
    int x2, y2;
    double slope;
    Line(int, int, int, int);

    void draw(SDL_Plotter&, int);
    double getLength();
};

#endif // SHAPES_H_INCLUDED

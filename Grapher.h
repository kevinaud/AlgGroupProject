#ifndef GRAPHER_H
#define GRAPHER_H

#include <ctime>
#include <cstdlib>
#include "Color.h"
#include "SDL_Plotter.h"

class Grapher{
public:
	Grapher(SDL_Plotter *p, int n, int x, int y);
    void plot(int** (*f)(int**,int**,int));
    void test();
    void setColor(Color);
private:
	int** (*func)(int**,int**,int);
    int n,
        x,
        y,
        w,
        h;
    SDL_Plotter *plotter;
    Color c;
};

#endif

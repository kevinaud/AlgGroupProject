#ifndef GRAPHER_H
#define GRAPHER_H

#include <ctime>
#include <cstdlib>
#include "SDL_Plotter.h"

class Grapher{
public:
	Grapher(SDL_Plotter *p, int n, int w, int h, int x, int y);
    void plot(int** (*f)(int**,int**,int));
    void test();
private:
	int** (*func)(int**,int**,int);
    int n,
        x,
        y,
        w,
        h;
    SDL_Plotter *plotter;
};

#endif

#ifndef GRAPHER_H
#define GRAPHER_H

#include <ctime>
#include <cstdlib>

class Grapher{
public:
	Grapher(int n, int w, int h, int x, int y);
    void plot(int** (*f)(int**,int**,int));
private:
	int** (*func)(int**,int**,int);
    int n,
        x,
        y,
        w,
        h;
};

#endif

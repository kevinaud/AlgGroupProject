#include "Grapher.h"

#define MAX_TIME 200.0

//DEBUGGING
#include <iostream>
using namespace std;
//DEBUGGING

int ** testFunc(int **A, int **B, int dim){
    SDL_Delay(10 * dim);
    int ** c = new int*[dim];
    for(int i = 0; i < dim; i++)
        c[i] = new int[dim];
    return c;
}

Grapher::Grapher(SDL_Plotter *p, int n, Point origin, Point size){
    this->n = n;	
    this->x = origin.x;
    this->y = origin.y;
    this->w = size.x;
    this->h = size.y;
    plotter = p;
    c = COLOR::BLACK;
}

void Grapher::test(){
    plot(&testFunc);
}

void Grapher::setColor(Color c){
    this->c = c;
}

void Grapher::plot(int** (*f)(int**,int**,int)){
    srand(time(NULL));
    
    int **A, **B, **C;

    int prevX = x;
    int prevY = y;
    for(int cur = 2; cur <= n; cur += 2){
        //allocate matrices
        A = new int*[cur];
        B = new int*[cur];
        for(int i = 0; i < cur; i++){
            A[i] = new int[cur];
            B[i] = new int[cur];
        }

        //generate random matrices
        for(int r = 0; r < cur; r++){
            for(int c = 0; c < cur; c++){
                A[r][c] = rand() % 10;
                B[r][c] = rand() % 10;
            }
        }

        //time algorithm
        int start = SDL_GetTicks();
        C = f(A,B,cur);
        int end = SDL_GetTicks(); 
        int time = end - start;

        cout << "time: " << time << endl;

        int normX = x + (double)w * ((double)cur / (double)n);
        int normY = y - (double)h * ((double)time / (double)MAX_TIME);
        plotter->plotPixel(normX, normY, c.r, c.g, c.b);

        Line l(Point(prevX, prevY),Point(normX, normY));
        l.draw(*plotter);

        prevX = normX;
        prevY = normY;

        plotter->update();

        //free matrices
        for(int i = 0; i < cur; i++){
            delete A[i];
            delete B[i];
            delete C[i];
        }
        delete A;
        delete B;
        delete C;
    }
}

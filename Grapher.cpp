#include "Grapher.h"
#include <unistd.h>

//DEBUGGING
#include <iostream>
using namespace std;
//DEBUGGING

int ** testFunc(int **A, int **B, int dim){
    SDL_Delay(10 * dim);
    return new int*[1];
}

Grapher::Grapher(SDL_Plotter *p, int n, int x, int y){
    this->n = n;	
    this->x = x;
    this->y = y;
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

    for(int cur = 2; cur < n; cur += 2){
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
        cout << x << ',' << y << endl;
        cout << "time " << time << endl;
        cout << "drawing " << x + (cur * 10) << ',' << y - time << endl;
        plotter->plotPixel(x + (10 * cur) , y - time, c.r, c.g, c.b);

        //free matrices
        for(int i = 0; i < cur; i++){
            delete A[i];
            delete B[i];
            //delete C[i];
        }
        delete A;
        delete B;
        delete C;
    }
}

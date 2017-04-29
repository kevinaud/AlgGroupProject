#include "Grapher.h"

//DEBUGGING
#include <iostream>
using namespace std;
//DEBUGGING

Grapher::Grapher(int n, int w, int h, int x, int y){
    this->n = n;	
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
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
        time_t start = time(NULL);
        C = f(A,B,cur);
        time_t end = time(NULL);
        cout << "coord" << endl
             << end - start << "," << cur << endl
             << "pos" << endl
             << (end - start) / h << ',' << cur / w << endl;

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

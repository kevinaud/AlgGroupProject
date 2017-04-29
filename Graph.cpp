#include "Graph.h"

#define START_MAX_TIME 50

//DEBUGGING
#include <iostream>
#include <cassert>
//DEBUGGING
using namespace std;

int ** testFunc(int **A, int **B, int dim){
    SDL_Delay(((double)dim * (double)dim) / 10.0);
    int ** c = new int*[dim];
    for(int i = 0; i < dim; i++)
        c[i] = new int[dim];
    return c;
}

Graph::Graph(SDL_Plotter *p, int n, Point origin, Point size){
    this->n = n;	
    maxTime = START_MAX_TIME;
    this->origin = origin;
    this->size = size;
    plotter = p;
    c = COLOR::BLACK;
    drawAxis();
}

void Graph::drawAxis(Color c){
    Point topLeft(origin.x,origin.y - size.y);
    Point bottomRight(origin.x + size.x, origin.y);
    //Point topRight(origin.x + size.x, origin.y - size.y);

    Color outlineColor = COLOR::BLUE;
    Line xAxis(origin, bottomRight);
    Line yAxis(origin, topLeft);
    //Line top(topLeft, topRight);
    //Line right(topRight, bottomRight);

    xAxis.setColor(outlineColor);
    yAxis.setColor(outlineColor);
    //top.setColor(outlineColor);
    //right.setColor(outlineColor);

    xAxis.draw(*plotter);
    yAxis.draw(*plotter);
    //top.draw(*plotter);
    //right.draw(*plotter);
}

void Graph::test(){
    plot(&testFunc);
}

void Graph::redraw(){
    plotter->clear();
    drawAxis();
    //recalculate y based on maxTime
    for(int j = 0; j < points.size(); j++){
        for(int k = 0; k < points[j].size(); k++){
            points[j][k].y = origin.y - (double)size.y * ((double)times[j][k] / (double)maxTime);
        }
    }

    //redraw points
    for(int j = 0; j < points.size(); j++){
        for(int k = 1; k < points[j].size(); k++){
            Line l(points[j][k - 1],points[j][k]);
            l.draw(*plotter);
        }
    }
}

void Graph::clear(){
    prevMax = START_MAX_TIME;
    maxTime = START_MAX_TIME;
    plotter->clear();
    points.clear();
    times.clear();
}

void Graph::setColor(Color c){
    this->c = c;
}

void Graph::plot(int** (*f)(int**,int**,int)){
    srand(time(NULL));
    
    int **A, **B, **C;

    int prevX = origin.x;
    int prevY = origin.y;
    points.push_back(vector<Point>());
    times.push_back(vector<int>());
    points.back().push_back(Point(prevX,prevY));
    times.back().push_back(1);

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
        int time = SDL_GetTicks();
        C = f(A,B,cur);
        time = SDL_GetTicks() - time; 

        //adjust y for the new maxTime
        if(time > maxTime){
            prevMax = maxTime;
            maxTime = time;
            redraw();
        }

        int normX = origin.x + (double)size.x * ((double)cur / (double)n);
        int normY = origin.y - (double)size.y * ((double)time / (double)maxTime);
        plotter->plotPixel(normX, normY, c.r, c.g, c.b);

        Line l(Point(prevX, prevY),Point(normX, normY));
        l.draw(*plotter);

        prevX = normX;
        prevY = normY;
        points.back().push_back(Point(prevX,prevY));
        times.back().push_back(time);

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

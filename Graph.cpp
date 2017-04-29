#include "Graph.h"

#define START_MAX_TIME 1
#define MOST_TESTS 100

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

Graph::Graph(SDL_Plotter &p, Font &f, int n, Point origin, Point size){
    this->n = n;
    maxTime = START_MAX_TIME;
    this->origin = origin;
    this->size = size;
    plotter = &p;
    font = &f;
    c = COLOR::BLACK;
    redraw();
}

void Graph::drawAxis(Color c){

    Point topLeft(origin.x,origin.y - size.y);
    Point bottomRight(origin.x + size.x, origin.y);
    Point topRight(origin.x + size.x, origin.y - size.y);

    Line xAxis(origin, bottomRight);
    Line yAxis(origin, topLeft);
    Line top(topLeft, topRight);
    //top.setStroke(20);
    //Line right(topRight, bottomRight);

    xAxis.setColor(c);
    yAxis.setColor(c);
    //top.setColor(COLOR::GREEN);
    //right.setColor(c);

    const int FONT_SIZE = 25;
    Font f(FONT_SIZE);

    f.drawString(*plotter, Point(topLeft.x - 75, topLeft.y - FONT_SIZE - 5), "Y(time)");

    Point middleBottom((origin.x + bottomRight.x) / 2, origin.y);
    f.drawString(*plotter, Point(middleBottom.x - 150, middleBottom.y + FONT_SIZE + 40), "X(matrix size)");

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
    if(nloc.x > -1 && nloc.y > -1)
        font->drawLabeledInt(*plotter,nloc,"N ",n);
    drawAxis();
    //recalculate y based on maxTime
    for(auto j : points){
        auto t = times.begin();
        for(int k = 0; k < j.second.size(); k++){
            j.second[k].y = origin.y - (double)size.y * ((double)t->second[k] / (double)maxTime);
        }
        t++;
    }

    //redraw points
    for(auto j : points){
        for(int k = 1; k < j.second.size(); k++){
            Line l(j.second[k - 1],j.second[k]);
            l.draw(*plotter);
        }
    }
}

void Graph::clear(){
    maxTime = START_MAX_TIME;
    plotter->clear();
    points.clear();
    times.clear();
    redraw();
}

void Graph::clear(MatrixMultFunc f){
    points.erase(f);
    times.erase(f);

    cout << "max: " << maxTime << endl;
    //find new maxTime
    maxTime = START_MAX_TIME;
    for(auto t : times)
        for(int k = 0; k < t.second.size(); k++)
            maxTime = max(maxTime,t.second[k]);
    cout << "newMax: " << maxTime << endl;

    redraw();
}

void Graph::setColor(Color c){
    this->c = c;
}

void Graph::setN(int n){
    this->n = n;
    redraw();
}

void Graph::setNLoc(Point nl){
    nloc = nl;
    redraw();
}

void Graph::plot(MatrixMultFunc f){
    srand(SDL_GetTicks());

    int **A, **B, **C;

    int prevX = origin.x;
    int prevY = origin.y;
    points[f] = vector<Point>();
    times[f] = vector<int>();
    points[f].push_back(Point(prevX,prevY));
    times[f].push_back(0);

    int step = n / MOST_TESTS;

    for(int cur = 2; cur <= n; cur += step){
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
        cout << cur << ',' << time << endl;

        //adjust y if new maxTime
        if(time > maxTime)
            maxTime = time + 20;
        int normX = origin.x + (double)size.x * ((double)cur / (double)n);
        int normY = origin.y - (double)size.y * ((double)time / (double)maxTime);
        plotter->plotPixel(normX, normY, c.r, c.g, c.b);

        prevX = normX;
        prevY = normY;
        points[f].push_back(Point(prevX,prevY));
        times[f].push_back(time);
        redraw();

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

DataPoint::DataPoint(Point data, Point loc) {
    this->data = data;
    this->loc = loc;
}

void DataPoint::draw(SDL_Plotter& p, Font f, int radius) {
    Point textLoc(loc.x - 75, loc.y + radius + 10);

    string result = "(";

    string str;
    int num = data.x;
    while(num){
        str.insert(0,1,(num % 10) + '0');
        num /= 10;
    }

    result = result + str;
    result = result + ",";

    num = data.y;
    str = "";
    while(num){
        str.insert(0,1,(num % 10) + '0');
        num /= 10;
    }

    result = result + str;
    result = result + ")";

    f.drawString(p, textLoc, result);
}













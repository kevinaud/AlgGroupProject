#include "Graph.h"

#define START_MAX_TIME 100000
#define MOST_TESTS 100
#define NS_PER_MS 100000

//DEBUGGING
#include <iostream>
#include <cassert>
//DEBUGGING
using namespace std;

int ** testFunc(int **A, int **B, int dim){
    SDL_Delay(dim * dim / 5000);
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
    nloc = Point(-1,-1);
    font = &f;
    c = COLOR::BLACK;
    eraser = COLOR::WHITE;
    redraw();
}

void Graph::drawAxis(){

    Point topLeft(origin.x,origin.y - size.y);
    Point bottomRight(origin.x + size.x, origin.y);

    Line xAxis(origin, bottomRight);
    Line yAxis(origin, topLeft);

    xAxis.setColor(c);
    xAxis.stroke = 3;
    yAxis.setColor(c);
    yAxis.stroke = 3;

    if(nloc.x > -1 || nloc.y > -1)
        font->drawLabeledInt(*plotter, nloc, "N ", n);

    font->drawString(*plotter, Point(topLeft.x - 75, topLeft.y - font->getSize() - 50), "Y(time)");

    Point middleBottom((origin.x + bottomRight.x) / 2, origin.y);
    font->drawString(*plotter, Point(middleBottom.x - 150, middleBottom.y + font->getSize() + 40), "X(matrix size)");

    int i = 0;
    int step = maxTime / 10;
    for (int y = origin.y; y >= topLeft.y; y -= (size.y / 10)){
        Line(Point(origin.x - 15, y), Point(origin.x, y)).draw(*plotter);
        string label = to_string(i * step / NS_PER_MS);
        int labelLength = font->calcStringLength(label);

        Point labelLoc(origin.x - 30 - labelLength, y - (0.5 * font->getSize()));
        Point rectLoc(labelLoc.x - 5, labelLoc.y - 5);
        int rectW = origin.x - 20 - rectLoc.x;
        int rectH = font->getSize() + 10;
        Rectangle rect(rectLoc, rectW, rectH);
        rect.setColor(COLOR::WHITE);
        rect.draw(*plotter);


        if (labelLoc.x < 0) {
            labelLoc.x = 0;
        }
        font->drawString(*plotter, labelLoc, label);
        i++;
    }

    i = 0;
    step = n / 10;
    for (int x = origin.x + 2; x <= bottomRight.x + 2; x += (size.x / 10)){
        Line(Point(x, origin.y + 15), Point(x, origin.y)).draw(*plotter);
        string label = to_string(i * step);
        int labelLength = font->calcStringLength(label);
        Point labelLoc(x - (labelLength / 2) - 3, origin.y + 25);
        font->drawString(*plotter, labelLoc, label);
        i++;
    }

    xAxis.draw(*plotter);
    yAxis.draw(*plotter);
}


void Graph::test(){
    plot(testFunc);
}

void Graph::erase(MatrixMultFunc f){
    if(f){
        for(int k = 1; k < points[f].size(); k++){
            Line l(points[f][k - 1],points[f][k]);
            l.setColor(eraser);
            l.stroke = 3;
            l.draw(*plotter);
        }
    }
    else{
        for(auto j : points){
            erase(j.first);
        }
    }
}

void Graph::redraw(){
    erase();
    drawAxis();
    
    //recalculate y based on maxTime
    for(auto j = points.begin(); j != points.end(); j++)
        for(int k = 0; k < times[j->first].size(); k++)
            j->second[k].y = origin.y - (double)size.y * ((double)times[j->first][k] / (double)maxTime);

    //redraw points
    for(auto j : points){
        for(int k = 1; k < j.second.size(); k++){
            Line l(j.second[k - 1],j.second[k]);
            l.setColor(colors[j.first]);
            l.stroke = 3;
            l.draw(*plotter);
        }
    }
}

void Graph::clear(){
    maxTime = START_MAX_TIME;
    erase();
    points.clear();
    times.clear();
    colors.clear();
    redraw();
}

void Graph::clear(MatrixMultFunc f){
    if(points.find(f) != points.end()){
        erase(f);

        points.erase(f);
        times.erase(f);
        colors.erase(f);

        //find new maxTime
        /*
        maxTime = START_MAX_TIME;
        for(auto t : times)
            for(int k = 0; k < t.second.size(); k++)
                maxTime = max(maxTime,t.second[k]);
        */

        redraw();
    }
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

void Graph::plot(MatrixMultFunc f, Color color){
    srand(SDL_GetTicks());

    int **A, **B, **C;

    int prevX = origin.x;
    int prevY = origin.y;

    clear(f);
    colors[f] = color;
    points[f].push_back(Point(prevX,prevY));
    times[f].push_back(0);

    int step = 2;
    if(n > MOST_TESTS)
        int step = n / MOST_TESTS;

    //allocate matrices
    A = new int*[n];
    B = new int*[n];
    for(int i = 0; i < n; i++){
        A[i] = new int[n];
        B[i] = new int[n];
    }

    for(int cur = 2; cur <= n; cur += step){

        //generate random matrices
        for(int r = 0; r < cur; r++){
            for(int c = 0; c < cur; c++){
                A[r][c] = rand() % 10;
                B[r][c] = rand() % 10;
            }
        }

        //time algorithm
        auto start = Clock::now();
        C = f(A,B,cur);
        auto end = Clock::now();
        unsigned int time = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

        //adjust y if new maxTime
        if(time > maxTime)
            maxTime = time + 10;
        int normX = origin.x + (double)size.x * ((double)cur / (double)n);
        int normY = origin.y - (double)size.y * ((double)time / (double)maxTime);

        prevX = normX;
        prevY = normY;
        points[f].push_back(Point(normX,normY));
        times[f].push_back(time);
        redraw();

        plotter->update();

    }
    //free matrices
    for(int i = 0; i < n; i++){
        delete A[i];
        delete B[i];
        delete C[i];
    }
    delete A;
    delete B;
    delete C;
}

DataPoint::DataPoint(Point data, Point loc) {
    this->data = data;
    this->loc = loc;
}

void DataPoint::draw(SDL_Plotter& p, Font f, int radius) {
    Point textLoc(loc.x - 75, loc.y - radius - f.getSize() - 10);
    Circle c(loc,radius);
    c.draw(p);

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


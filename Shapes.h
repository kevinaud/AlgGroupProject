#include <algorithm>
#include <cmath>

#include "SDL_Plotter.h"
#include "Color.h"

#ifndef SHAPES_H_INCLUDED
#define SHAPES_H_INCLUDED

class Point {
public:
    Point();
    Point(int, int);
    Point(const Point&);

    int x;
    int y;
};

class Line {
public:
    Line(Point, Point);

    Point p1;
    Point p2;
    int stroke = 1;
    Color color = Color(0, 0, 0);

    void draw(SDL_Plotter&);
    void offsetDraw(SDL_Plotter&, Point);

    void setColor(Color color);
    void setStroke(int);
};

class Rectangle {
public:
    Rectangle(Point, int, int);

    Point loc;
    int width;
    int height;
    Color color = COLOR::BLACK;

    void draw(SDL_Plotter&);

    void setColor(Color);
};

#endif // SHAPES_H_INCLUDED

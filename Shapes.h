#include <algorithm>
#include <cmath>

#include "SDL_Plotter.h"
#include "Color.h"

#ifndef SHAPES_H_INCLUDED
#define SHAPES_H_INCLUDED

class Point {
public:
    int x;
    int y;
    Color color = COLOR::BLACK;

    Point();
    Point(int, int);
    Point(const Point&);
    bool operator==(const Point &other) const;
    void setColor(Color color);
    void draw(SDL_Plotter&);
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

class Circle{
public:
    Circle(Point,int);

    Point center;
    int radius;
    bool filled;
    Color color = COLOR::BLACK;

    void draw(SDL_Plotter&);

    void setColor(Color);

};

#endif // SHAPES_H_INCLUDED

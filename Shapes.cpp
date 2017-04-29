#include "Shapes.h"

#include <cassert>

Point::Point() {
    x = 0;
    y = 0;
}

Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}

Point::Point(const Point& p) {
    x = p.x;
    y = p.y;
}

void Point::setColor(Color color) {
    this->color = color;
}

void Point::draw(SDL_Plotter& p) {
    p.plotPixel(x, y, color.r, color.g, color.b);
}

bool Point::operator==(const Point &other) const {
    return this->x == other.x && this->y == other.y;
}

Line::Line(Point p1, Point p2) {
    this->p1 = p1;
    this->p2 = p2;
}

void Line::setStroke(int stroke) {
    this->stroke = stroke;
}

void Line::setColor(Color color) {
    this->color = color;
}

void Line::draw(SDL_Plotter& p) {
    offsetDraw(p, Point(0, 0));
}

void Line::offsetDraw(SDL_Plotter& p, Point loc) {

    int dx = p2.x - p1.x;
    int dy = p2.y - p1.y;
    int numSteps;

    if (abs(dx) > abs(dy)) {
       numSteps = abs(dx);
    } else {
       numSteps = abs(dy);
    }

    double Xinc = (double)dx / (double)numSteps;
    double Yinc = (double)dy / (double)numSteps;

    double x = (double)p1.x + loc.x;
    double y = (double)p1.y + loc.y;

    for(int i = 0; i < numSteps; i++) {
        x = x + Xinc;
        y = y + Yinc;

        for (int i = 0; i < stroke; i++) {
            for (int j = 0; j < stroke; j++) {
                p.plotPixel(x + i, y + j, color.r, color.g, color.b);
            }
        }
    }
}

Rectangle::Rectangle(Point loc, int width, int height){
    this->loc = loc;
    this->width = width;
    this->height = height;
}

void Rectangle::draw(SDL_Plotter& p){
    for (int x = loc.x; x < loc.x + width; x++) {
        for (int y = loc.y; y < loc.y + height; y++) {
            p.plotPixel(x, y, color.r, color.g, color.b);
        }
    }
}

void Rectangle::setColor(Color color) {
    this->color = color;
}

Circle::Circle(Point c, int r){
    center = c;
    radius = r;
    filled = true;
}

void Circle::draw(SDL_Plotter &p){

    for(double y = 0; y < radius; y += 1.0){
        int x = sqrt(radius * radius - y * y);

        if(filled){
            Line bottom(Point(center.x + x, center.y + y), Point(center.x - x, center.y + y));
            bottom.setColor(color);
            bottom.draw(p);
            Line top(Point(center.x + x, center.y - y), Point(center.x - x, center.y - y));
            top.setColor(color);
            top.draw(p);
        }
        else{
            p.plotPixel(center.x + x,center.y + y, color.r, color.g, color.b);
            p.plotPixel(center.x - x,center.y + y, color.r, color.g, color.b);
            p.plotPixel(center.x + x,center.y - y, color.r, color.g, color.b);
            p.plotPixel(center.x - x,center.y - y, color.r, color.g, color.b);
        }
    }
}

void Circle::setColor(Color c){
    color = c;
}

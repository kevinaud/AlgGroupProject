#include "Shapes.h"
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

Line::Line(Point p1, Point p2) {
    this->p1 = p1;
    this->p2 = p2;
}

void Line::setColor(Color color) {
    this->color = color;
}

void Line::setStroke(int stroke) {
    this->stroke = stroke;
}

void Line::draw(SDL_Plotter& p) {

    int dx = p2.x - p1.x;
    int dy = p2.y - p1.y;
    int numSteps;

    if (abs(dx) > abs(dy)) {
       numSteps = abs(dx);
    } else {
       numSteps = abs(dy);
    }

    double Xinc = (1.0 * dx) / numSteps;
    double Yinc = (1.0 * dy) / numSteps;

    double x = (double)p1.x;
    double y = (double)p1.y;

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


















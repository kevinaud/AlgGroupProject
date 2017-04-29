#include "Shapes.h"

Line::Line(int X1, int Y1, int X2, int Y2) {
    x1 = min(X1, X2);
    y1 = min(Y1, Y2);
    x2 = max(X1, X2);
    y2 = max(Y1, Y2);
    slope = ((y2 - y1) * 1.0) / (x2 - x1);
}

void Line::draw(SDL_Plotter& p, int stroke) {

    /*double dist = getLength();
    double step = (x2 - x1) / dist;
    for(double d = 0.0; d < dist; d += step) {
        int x = (int)(dist + x1 + 0.5);
        if (x1 != x2){
            p.plotPixel(x, (y1 + (x * slope)), 255, 0 , 0);
        } else {
            p.plotPixel(x, (y1 + dist), 255, 0 , 0);
        }
    }*/
    //if (slope > -1 && slope < 1) {
        for(int x = x1; x < x2; x++) {
            p.plotPixel(x, (y1 + (slope * x)), 255, 0, 0);
        }
    /*} else {
        for (int y = y1; y < y2; y++) {
            p.plotPixel()
        }
    }*/

}

double Line::getLength() {
    return sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
}

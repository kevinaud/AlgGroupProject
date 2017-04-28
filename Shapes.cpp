#include "Shapes.h"

Line::Line(int X1, int Y1, int X2, int Y2) {
    x1 = X1;
    y1 = Y1;
    x2 = X2;
    y2 = Y2;
}

void Line::draw(SDL_Plotter& p, int stroke) {
    for (int x = x1; x < x2; x++) {
        for (int y = y1; y < y2; y++){
            for (int w = 0; w < stroke; w++) {
                for (int h = 0; h < stroke; h++) {
                    p.plotPixel(x + w, y + h, 255, 0 , 0);
                }
            }
        }
    }
}

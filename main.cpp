#include <iostream>

#include "SDL_Plotter.h"
#include "Shapes.h"
#include "Color.h"
#include "Font.h"
#include "Grapher.h"

using namespace std;

int main(int argc, char ** argv)
{

    SDL_Plotter g(800, 1280);

    Point origin(100,700);
    Point size(700,600);
    Point topLeft(origin.x,origin.y - size.y);
    Point bottomRight(origin.x + size.x, origin.y);
    Point topRight(origin.x + size.x, origin.y - size.y);

    Color outlineColor = COLOR::BLUE;
    Line xAxis(origin, bottomRight);
    Line yAxis(origin, topLeft);
    Line top(topLeft, topRight);
    Line right(topRight, bottomRight);

    xAxis.setColor(outlineColor);
    yAxis.setColor(outlineColor);
    top.setColor(outlineColor);
    right.setColor(outlineColor);

    xAxis.draw(g);
    yAxis.draw(g);
    top.draw(g);
    right.draw(g);

    Grapher graph(&g, 10, origin, size);
    graph.test();

    while(!g.getQuit()){
        g.update();
    	if(g.kbhit())
    	    g.getKey();
    }

    return 0;
}

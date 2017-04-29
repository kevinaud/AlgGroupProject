#include <iostream>

#include "SDL_Plotter.h"
#include "Shapes.h"
<<<<<<< HEAD
#include "DivideAndConquer.h"
=======
#include "Color.h"
#include "Font.h"
#include "Grapher.h"
>>>>>>> 53d6b3855c7e285a0b82220782e7dd4eb1b5715c

using namespace std;

int main(int argc, char ** argv)
{

<<<<<<< HEAD



=======
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
>>>>>>> 53d6b3855c7e285a0b82220782e7dd4eb1b5715c

    return 0;
}

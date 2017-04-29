#include <iostream>

#include "SDL_Plotter.h"
#include "Shapes.h"
#include "Color.h"
#include "Grapher.h"

using namespace std;

int main(int argc, char ** argv)
{

    SDL_Plotter g(800, 1280);

    Line line1(Point(100, 700), Point(1180, 700));

    line1.setColor(COLOR::GREEN);
    line1.setStroke(3);
    line1.draw(g);

    Line line2(Point(100, 100), Point(100, 550));
    line2.draw(g);

    Rectangle r(Point(500, 500), 50, 50);
    r.setColor(COLOR::BLUE);
    r.draw(g);

    Grapher graph(&g, 100, 100, 700);
    graph.test();

    while(!g.getQuit()){
        g.update();
    	if(g.kbhit())
    	    g.getKey();
    }

    return 0;
}

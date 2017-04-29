#include <iostream>

#include "SDL_Plotter.h"
#include "Shapes.h"
#include "DivideAndConquer.h"
#include "Color.h"
#include "Graph.h"
#include "Font.h"
#include "Grapher.h"

using namespace std;

int main(int argc, char ** argv)
{

    SDL_Plotter g(800, 1280);

    Point origin(100,700);
    Point graphSize(700,600);
    int n = 100;

    Graph graph(&g, n, origin, graphSize);
    graph.test();

    while(!g.getQuit()){
        g.update();
    	if(g.kbhit())
    	    g.getKey();
    }

    return 0;
}

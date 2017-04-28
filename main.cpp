#include <iostream>

#include "SDL_Plotter.h"
#include "Shapes.h"

using namespace std;

int main(int argc, char ** argv)
{

    SDL_Plotter g(1000,1000);

    Line line(30, 30, 70, 70);
    line.draw(g, 5);
    g.update();

    /*int x,y, xd, yd;
    int R,G,B;

    while (!g.getQuit())
    {
    	x = rand()%g.getCol();
    	y = rand()%g.getRow();
    	R = rand()%256;
    	G = rand()%256;
    	B = rand()%256;
    	for(xd = 0; xd < 2 && x + xd < g.getCol(); xd++ ){
    		for(yd = 0; yd < 2 && y + yd < g.getRow(); yd++ ){
    	    	g.plotPixel( x + xd, y + yd, R, G, B);
    	    	g.plotPixel( x + xd, y + yd, 0, G, 0);
    		}
    	}
    	g.update();
    	if(g.kbhit()){
    	    g.getKey();
    	}
    }*/
    return 0;
}

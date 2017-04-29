#include <iostream>

#include "SDL_Plotter.h"
#include "Shapes.h"

using namespace std;

int main(int argc, char ** argv)
{

    SDL_Plotter g(800, 1280);

    Line line1(100, 700, 1180, 700);
    line1.draw(g, 5);

    Line line2(50, 100, 200, 600);
    line2.draw(g, 5);

    //Line line2(100, 700, 100, 100);
    //line2.draw(g, 5);
    g.update();

    while(!g.getQuit()) {

    }

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

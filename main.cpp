#include <iostream>

#include "SDL_Plotter.h"
#include "Shapes.h"
#include "DivideAndConquer.h"
#include "Color.h"
#include "Graph.h"
#include "Font.h"


using namespace std;

const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 800;

int main(int argc, char ** argv)
{


    SDL_Plotter g(WINDOW_HEIGHT, WINDOW_WIDTH);

    Point origin(100,700);
    Point graphSize(700,600);
    int n = 100;

    Graph graph(&g, n, origin, graphSize);
    graph.test();
    Font f(20);

    bool on[] = {false, false, false, false};
    f.drawString(g,Point(850, WINDOW_HEIGHT/2), "B Brute Force");
    f.drawString(g,Point(850, WINDOW_HEIGHT/2 + 30),"D Divide and Conquer");
    f.drawString(g,Point(850, WINDOW_HEIGHT/2 + 60),"S Straussen");
    f.drawString(g,Point(850, WINDOW_HEIGHT/2 + 90),"T Threaded Straussen");




    while(!g.getQuit()){
        g.update();
    	if(g.kbhit()){
            char c = g.getKey();
            switch(c){
            case 'B':
                    f.drawString(g,Point(250,500), "Brute Force");
                f.drawString(g,Point(250,500), "Brute Force");
                break;
            case 'D':
                f.drawString(g,Point(250,500), "Divide And Conquer");
                break;
            case 'S':
                f.drawString(g,Point(250,500), "Strassen");
                break;
            case 'T':
                f.drawString(g,Point(250,500), "Threaded Strassen");
                break;
            case 'Q':
                 f.drawString(g,Point(250,500), "Quit");
                break;
            default:
                 f.drawString(g,Point(250,500), "Other");
                break;

            }
    	}

    }

    return 0;
}
